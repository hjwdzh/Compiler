#include "expression.h"
#include "specify.h"
#include "assertion.h"
#include "calculation.h"

void argument_expression_list(struct ArgumentExpressionList* node)
{
    if (node->type == 1)
    {
        argument_expression_list(node->argumentExpressionList);
    }
    push_arg(assignment_expression(node->assignmentExpression));
}


struct Symbol* primary_expression(struct PrimaryExpression* node, struct Symbol** orig_symbol)
{
    switch (node->type) {
        case 0:
            *orig_symbol = name2symbol(node->identifier, 0);
            return *orig_symbol;
        case 1://INT
            sprintf(buf, "%d", node->iValue);
            *orig_symbol = new_symbol(buf, 0, 2, 1 << 4, 0, 2, 0);
            return *orig_symbol;
        case 2://char
            sprintf(buf, "%d", (int)node->cValue);
            *orig_symbol = new_symbol(buf, 0, 2, 1 << 2, 0, 2, 0);
            return *orig_symbol;
        case 3://f
            sprintf(buf, "%f", node->fValue);
            return new_symbol(buf, 0, 2, 1 << 6, 0, 2, 0);
        case 4://d
            sprintf(buf, "%lf", node->dValue);
            *orig_symbol = new_symbol(buf, 0, 2, 1 << 7, 0, 2, 0);
            return *orig_symbol;
        case 5:
            *orig_symbol = new_symbol(node->literal, 0, 2, (PTR_LENGTH == 8) ? (1 << 5) : (1 << 4), 1, 2, 0);
            return *orig_symbol;
        case 6:
            *orig_symbol = expression_func(node->expression);
            return *orig_symbol;
        default:
            return 0;
    }
}

struct Symbol* postfix_expression(struct PostfixExpression* node, struct Symbol** orig_symbol)
{
    struct Symbol* symbol, *ref, *newSymbol, *symbol1;
    switch (node->type) {
        case 0:
            return primary_expression(node->primaryExpression, orig_symbol);
        case 1:
            symbol = load_symbol(postfix_expression(node->postfixExpression, orig_symbol));
            test_referenceable(symbol);
            ref = load_symbol(expression_func(node->expression));
            *orig_symbol = new_symbol("", symbol->storage, 0, symbol->specifier, symbol->stars - 1, 0, 0);
            ADDSTRING("  ");
            code_gen_symbol('%', *orig_symbol);
            ADDSTRING(" = getelementptr inbounds ");
            code_gen_type_specifier(symbol->specifier, 0, symbol->length, symbol->stars);
            ADDSTRING(" ");
            if (symbol->depth == 0)
                code_gen_symbol('@', symbol);
            else
                code_gen_symbol('%', symbol);
            ADDSTRING(", i32 0, ");
            ADDSTRING(PTR_LEN_TYPE);
            ADDSTRING(" ");
            code_gen_symbol(0, ref);
            ADDSTRING("\n");
            ADDSTRING("  ");
            newSymbol = new_symbol("", 0, 2, symbol->specifier, symbol->stars - 1, 0, 0);
            code_gen_symbol('%', newSymbol);
            ADDSTRING(" = load ");
            code_gen_type_specifier(symbol->specifier, 0, (*orig_symbol)->length, symbol->stars);
            ADDSTRING(" ");
            code_gen_symbol('%', *orig_symbol);
            ADDSTRING(", align ");
            if (newSymbol->stars)
            {
                if (PTR_LENGTH == 8)
                {
                    ADDSTRING("8\n");
                }
                else
                {
                    ADDSTRING("4\n");
                }
            }
            else
            {
                int len = len_gen_type_specifier(newSymbol->specifier);
                sprintf(buf, "%d\n", len);
                ADDSTRING(buf);
            }
            return newSymbol;
        case 2:
        case 3:
            symbol = postfix_expression(node->postfixExpression, orig_symbol);
            test_functionable(symbol);
            if (node->type == 3)
            {
                argument_expression_list(node->argumentExpressionList);
            }
            newSymbol = new_symbol("", symbol->storage, 2, symbol->specifier, symbol->stars, 0, symbol->length);
            code_gen_symbol('%', symbol);
            ADDSTRING(" = call ");
            code_gen_type_specifier(symbol->specifier, 0, symbol->length, symbol->stars);
            ADDSTRING(" ");
            code_gen_symbol('%', symbol);
            ADDSTRING("(");
            if (node->type == 3)
            {
                pop_arg();
            }
            ADDSTRING(")");
            *orig_symbol = 0;
            return newSymbol;
        case 4:
        case 5:
            // to do: struct
            return 0;
        case 6:
        case 7:
            symbol = load_symbol(postfix_expression(node->postfixExpression, orig_symbol));
            test_changeable(*orig_symbol);
            symbol1 = new_symbol("", symbol->storage, 2, symbol->specifier, symbol->stars, 0, symbol->length);
            ADDSTRING("  ");
            code_gen_symbol('%', symbol1);
            ADDSTRING(" = ");
            if ((symbol->specifier & (3 << 6)) > 0)
            {
                ADDSTRING("f");
            }
            if (node->type == 6)
            {
                ADDSTRING("add ");
            }
            else
            {
                ADDSTRING("sub ");
            }
            code_gen_type_specifier(symbol->specifier,1,symbol->length, symbol->stars);
            ADDSTRING(" ");
            code_gen_symbol('%', symbol);
            ADDSTRING(", ");
            if ((symbol->specifier & (3 << 6)) > 0)
            {
                ADDSTRING("1.000000e+00\n");
            }
            else
            {
                ADDSTRING("1\n");
            }
            ADDSTRING("  store ");
            code_gen_type_specifier(symbol->specifier,0,symbol->length, symbol->stars);
            ADDSTRING(" ");
            code_gen_symbol('%', symbol1);
            ADDSTRING(", ");
            code_gen_type_specifier(symbol->specifier,0,symbol->length, symbol->stars);
            ADDSTRING("* ");
            code_gen_symbol('%', *orig_symbol);
            ADDSTRING(", align ");
            int l = len_gen_type_specifier(symbol->specifier);
            sprintf(buf, "%d", l);
            ADDSTRING(buf);
            ADDSTRING("\n");
            return symbol;
        default:
            return 0;
    }
}

struct Symbol* unary_expression(struct UnaryExpression* node, struct Symbol** orig_symbol)
{
    int len;
    struct Symbol *symbol, *symbol1 = NULL;
    switch (node->type) {
        case 0:
            return postfix_expression(node->postfixExpression, orig_symbol);
        case 1:
        case 2:
            symbol = load_symbol(unary_expression(node->unaryExpression, orig_symbol));
            test_changeable(*orig_symbol);
            if (node->type == 2)
                symbol1 = test_calculable(symbol, '+');
            else
                symbol1 = test_calculable(symbol, '-');
            if (symbol1)
                return symbol1;
            symbol1 = new_symbol("", symbol->storage, symbol->qualifier, symbol->specifier, symbol->stars - 1, 0, symbol->length);
            code_gen_symbol('%', symbol1);
            if ((symbol->specifier & (3 << 6)) > 0)
            {
                ADDSTRING("f");
            }
            if (node->type == 2)
            {
                ADDSTRING("add ");
            }
            else
            {
                ADDSTRING("sub ");
            }
            code_gen_type_specifier(symbol->specifier,1,symbol->length, symbol->stars);
            code_gen_symbol('%', symbol);
            ADDSTRING(", ");
            if ((symbol->specifier & (3 << 6)) > 0)
            {
                ADDSTRING("1.000000e+00\n");
            }
            else
            {
                ADDSTRING("1\n");
            }
            ADDSTRING("store ");
            code_gen_type_specifier(symbol->specifier,0,symbol->length, symbol->stars);
            ADDSTRING(" ");
            code_gen_symbol('%', symbol1);
            ADDSTRING(", ");
            code_gen_type_specifier(symbol->specifier,0,symbol->length, symbol->stars);
            ADDSTRING("* ");
            code_gen_symbol('%', *orig_symbol);
            ADDSTRING(", align ");
            int l = len_gen_type_specifier(symbol->specifier);
            sprintf(buf, "%d", l);
            ADDSTRING(buf);
            ADDSTRING("\n");
            *orig_symbol = 0;
            break;
            
        case 3:
            symbol = cast_expression(node->castExpression);
            switch (node->unaryOperator) {
                case 1:
                    test_pointable(symbol);
                    symbol = load_symbol(symbol);
                    *orig_symbol = 0;
                    symbol1 = new_symbol("", symbol->storage, 2, symbol->specifier, symbol->stars + 1, 0, 0);
                    ADDSTRING("  ");
                    code_gen_symbol('%', symbol1);
                    ADDSTRING(" = getelementptr inbounds ");
                    code_gen_type_specifier(symbol->specifier, 0, symbol->length, symbol->stars);
                    ADDSTRING(" ");
                    code_gen_symbol('%', symbol);
                    ADDSTRING(", ");
                    ADDSTRING(PTR_LEN_TYPE);
                    ADDSTRING(" 0\n");
                    break;
                case 2:
                    test_referenceable(symbol);
                    symbol = load_symbol(symbol);
                    symbol1 = new_symbol("", symbol->storage, 2, symbol->specifier, symbol->stars - 1, 0, symbol->length);
                    *orig_symbol = symbol1;
                    ADDSTRING("  ");
                    code_gen_symbol('%', symbol1);
                    ADDSTRING(" = load ");
                    code_gen_type_specifier(symbol->specifier, 0, symbol->length, symbol->stars);
                    code_gen_symbol('%', symbol);
                    ADDSTRING(" ");
                    code_gen_symbol('%', symbol);
                    ADDSTRING(", align 8\n");
                    break;
                case 3:
                    test_regular(symbol);
                    symbol1 = symbol;
                    *orig_symbol = 0;
                    break;
                case 4:
                    test_regular(symbol);
                    symbol = load_symbol(symbol);
                    symbol1 = test_calculable(symbol, 'n');
                    if (symbol1)
                    {
                        return symbol1;
                    }
                    symbol1 = new_symbol("", symbol->storage, 2, symbol->specifier, symbol->stars, 0, 0);
                    *orig_symbol = symbol;
                    ADDSTRING("  ");
                    code_gen_symbol('%', symbol1);
                    if ((symbol->specifier & (3 << 6)) != 0)
                    {
                        ADDSTRING(" = f");
                    }
                    else
                    {
                        ADDSTRING(" = ");
                    }
                    ADDSTRING("sub ");
                    code_gen_type_specifier(symbol->specifier,1, symbol->length, symbol->stars);
                    ADDSTRING(" ");
                    if ((symbol->specifier & (3 << 6)) != 0)
                    {
                        ADDSTRING("0.000000e+00");
                    }
                    else
                    {
                        ADDSTRING("0");
                    }
                    ADDSTRING(", ");
                    code_gen_symbol('%', symbol);
                    ADDSTRING("\n");
                    *orig_symbol = 0;
                    break;
                case 5:
                    test_integer(symbol);
                    symbol = load_symbol(symbol);
                    symbol1 = test_calculable(symbol, '~');
                    if (symbol1)
                    {
                        return symbol1;
                    }
                    *orig_symbol = 0;
                    symbol = cast_symbol(symbol, 16, 0);
                    symbol1 = new_symbol("", symbol->storage, symbol->qualifier, symbol->specifier, symbol->stars, 0, symbol->length);
                    ADDSTRING("  ");
                    code_gen_symbol('%', symbol1);
                    ADDSTRING(" = xor ");
                    code_gen_type_specifier(symbol->specifier,0, symbol->length, symbol->stars);
                    ADDSTRING(" ");
                    code_gen_symbol('%', symbol);
                    ADDSTRING(", -1");
                    ADDSTRING("\n");
                    break;
                case 6:
                    *orig_symbol = 0;
                    symbol1 = test_calculable(symbol, '!');
                    symbol = load_symbol(symbol);
                    if (symbol1)
                    {
                        return symbol1;
                    }
                    symbol1 = new_symbol("0", 0, 2, 16, 0, 2, 0);
                    symbol1 = equality_symbol(symbol, symbol1, 2, 1);
                    break;
                default:
                    break;
            }
            break;
            
        case 4:
            *orig_symbol = 0;
            symbol = unary_expression(node->unaryExpression, orig_symbol);
            if (symbol->stars)
                len = PTR_LENGTH;
            else
                len = len_gen_type_specifier(symbol->specifier);
            sprintf(buf, "%d", len);
            symbol1 = new_symbol(buf, 0, 2, 4, 0, 2, 0);
            break;
            
        case 5:
            *orig_symbol = 0;
            len = len_gen_type_name(node->typeName);
            sprintf(buf, "%d", len);
            symbol1 = new_symbol(buf, 0, 2, 4, 0, 2, 0);
            break;
            
        default:
            break;
    }
    return symbol1;
}

struct Symbol* cast_expression(struct CastExpression* node)
{
    struct Symbol* symbol = 0;
    if (node->type == 0)
        return unary_expression(node->unaryExpression, &symbol);
    int specifier, stars;
    typename2specifier(node->typeName, &specifier, &stars);
    symbol = load_symbol(symbol);
    symbol = cast_symbol(symbol, specifier, stars);
    return cast_expression(node->castExpression);
}

struct Symbol* multiplicative_expression(struct MultiplicativeExpression* node)
{
    if (node->type == 0)
        return cast_expression(node->castExpression);
    struct Symbol* symbol1 = load_symbol(multiplicative_expression(node->multiplicativeExpression));
    struct Symbol* symbol2 = load_symbol(cast_expression(node->castExpression));
    return multiplicative_symbol(symbol1, symbol2, node->type);
}

struct Symbol* additive_expression(struct AdditiveExpression* node)
{
    if (node->type == 0)
        return multiplicative_expression(node->multiplicativeExpression);
    struct Symbol* symbol1 = load_symbol(additive_expression(node->additiveExpression));
    struct Symbol* symbol2 = load_symbol(multiplicative_expression(node->multiplicativeExpression));
    return additive_symbol(symbol1, symbol2, node->type);
}

struct Symbol* shift_expression(struct ShiftExpression* node)
{
    if (node->type == 0)
        return additive_expression(node->additiveExpression);
    struct Symbol* symbol1 = load_symbol(shift_expression(node->shiftExpression));
    struct Symbol* symbol2 = load_symbol(additive_expression(node->additiveExpression));
    return shift_symbol(symbol1, symbol2, node->type);
}


struct Symbol* relational_expression(struct RelationalExpression* node)
{
    if (node->type == 0)
        return shift_expression(node->shiftExpression);
    struct Symbol* symbol1 = load_symbol(relational_expression(node->relationalExpression));
    struct Symbol* symbol2 = load_symbol(shift_expression(node->shiftExpression));
    test_relation(&symbol1, &symbol2);
    struct Symbol* symbol3;
    if (node->type == 1)
        symbol3 = test_calculable2(&symbol1, &symbol2, '<');
    else
        symbol3 = test_calculable2(&symbol1, &symbol2, '>');
    if (symbol3)
        return symbol3;
    symbol3 = new_symbol("", 0, 2, 1, 0, 0, 0);
    char c = 's';
    if ((symbol1->specifier & (1 << 9)) > 0 || symbol1->stars)
        c = 'u';
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    if (symbol2->stars == 0 && (symbol2->specifier & (3 << 6)) != 0)
    {
        ADDSTRING(" = fcmp ");
        if (node->type == 1 || node->type == 3)
        {
            ADDSTRING("olt ");
        }
        else
        {
            ADDSTRING("ogt ");
        }
    }
    else
    {
        ADDSTRING(" = icmp ");
        *g_ptr++ = c;
        if (node->type == 1 || node->type == 3)
        {
            ADDSTRING("lt ");
        }
        else
        {
            ADDSTRING("gt ");
        }
    }
    code_gen_type_specifier(symbol1->specifier,0, symbol1->length, symbol1->stars);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol('%', symbol2);
    ADDSTRING("\n");
    return symbol3;
}

struct Symbol* equality_expression(struct EqualityExpression* node)
{
    if (node->type == 0)
        return relational_expression(node->relationalExpression);
    struct Symbol* symbol1 = load_symbol(equality_expression(node->equalityExpression));
    struct Symbol* symbol2 = load_symbol(relational_expression(node->relationalExpression));
    return equality_symbol(symbol1, symbol2, node->type, 0);
}

struct Symbol* and_expression(struct AndExpression* node)
{
    if (node->type == 0)
        return equality_expression(node->equalityExpression);
    struct Symbol* symbol1 = load_symbol(and_expression(node->andExpression));
    struct Symbol* symbol2 = load_symbol(equality_expression(node->equalityExpression));
    return and_symbol(symbol1, symbol2, node->type);
}

struct Symbol* exclusive_or_expression(struct ExclusiveOrExpression* node)
{
    if (node->type == 0)
        return and_expression(node->andExpression);
    struct Symbol* symbol1 = load_symbol(exclusive_or_expression(node->exclusiveOrExpression));
    struct Symbol* symbol2 = load_symbol(and_expression(node->andExpression));
    return exclusive_or_symbol(symbol1, symbol2, node->type);
}

struct Symbol* inclusive_or_expression(struct InclusiveOrExpression* node)
{
    if (node->type == 0)
        return exclusive_or_expression(node->exclusiveOrExpression);
    struct Symbol* symbol1 = load_symbol(inclusive_or_expression(node->inclusiveOrExpression));
    struct Symbol* symbol2 = load_symbol(exclusive_or_expression(node->exclusiveOrExpression));
    return inclusive_or_symbol(symbol1, symbol2, node->type);
}

struct Symbol* logical_and_expression(struct LogicalAndExpression* node)
{
    if (node->type == 0)
        return inclusive_or_expression(node->inclusiveOrExpression);
    struct Symbol* symbol1 = load_symbol(logical_and_expression(node->logicalAndExpression));
    struct Symbol* symbol2 = load_symbol(inclusive_or_expression(node->inclusiveOrExpression));
    struct Symbol* symbol3 = test_calculable2(&symbol1, &symbol2, 'a');
    if (symbol3)
        return symbol3;
    symbol3 = new_symbol("0", 0, 2, 16, 0, 2, 0);
    symbol3 = equality_symbol(symbol1, symbol3, 2, 1);
    ADDSTRING("  br i1 ");
    code_gen_symbol('%', symbol3);
    struct Symbol* label1 = new_symbol("", 0, 0, 0, 0, 0, 0);
    struct Symbol* label2 = new_symbol("", 0, 0, 0, 0, 0, 0);
    ADDSTRING(", label ");
    code_gen_symbol('%', label1);
    ADDSTRING(", label ");
    code_gen_symbol('%', label2);
    ADDSTRING("\n; <label>:");
    code_gen_symbol(0, label1);
    ADDSTRING("\n");
    symbol1 = equality_symbol(symbol2, symbol3, 2, 1);
    ADDSTRING("  br label ");
    code_gen_symbol('%', label2);
    ADDSTRING("\n; <label>:");
    code_gen_symbol(0, label2);
    ADDSTRING("\n");
    ADDSTRING("  ");
    symbol2 = new_symbol("", 0, 2, 2, 0, 0, 0);
    code_gen_symbol('%', symbol2);
    ADDSTRING(" = phi i1 [ false, %0 ], [ ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol(0, label2);
    ADDSTRING(" ]\n");
    return symbol2;
}

struct Symbol* logical_or_expression(struct LogicalOrExpression* node)
{
    if (node->type == 0)
        return logical_and_expression(node->logicalAndExpression);
    struct Symbol* symbol1 = load_symbol(logical_or_expression(node->logicalOrExpression));
    struct Symbol* symbol2 = load_symbol(logical_and_expression(node->logicalAndExpression));
    struct Symbol* symbol3 = test_calculable2(&symbol1, &symbol2, 'a');
    if (symbol3)
        return symbol3;
    symbol3 = new_symbol("0", 0, 2, 16, 0, 2, 0);
    symbol3 = equality_symbol(symbol1, symbol3, 2, 1);
    ADDSTRING("  br i1 ");
    code_gen_symbol('%', symbol3);
    struct Symbol* label1 = new_symbol("", 0, 0, 0, 0, 0, 0);
    struct Symbol* label2 = new_symbol("", 0, 0, 0, 0, 0, 0);
    ADDSTRING(", label ");
    code_gen_symbol('%', label2);
    ADDSTRING(", label ");
    code_gen_symbol('%', label1);
    ADDSTRING("\n; <label>:");
    code_gen_symbol(0, label1);
    ADDSTRING("\n");
    symbol1 = equality_symbol(symbol2, symbol3, 2, 1);
    ADDSTRING("  br label ");
    code_gen_symbol('%', label2);
    ADDSTRING("\n; <label>:");
    code_gen_symbol(0, label2);
    ADDSTRING("\n");
    ADDSTRING("  ");
    symbol2 = new_symbol("", 0, 2, 2, 0, 0, 0);
    code_gen_symbol('%', symbol2);
    ADDSTRING(" = phi i1 [ true, %0 ], [ ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol(0, label2);
    ADDSTRING(" ]\n");
    return symbol2;
}

struct Symbol* conditional_expression(struct ConditionalExpression* node)
{
    struct Symbol* symbol = logical_or_expression(node->logicalOrExpression);
    if (node->type == 0)
        return symbol;
    ADDSTRING("  br i1 ");
    code_gen_symbol('%', symbol);
    struct Symbol* label1 = new_symbol("", 0, 0, 0, 0, 0, 0);
    struct Symbol* label2 = new_symbol("", 0, 0, 0, 0, 0, 0);
    struct Symbol* label3 = new_symbol("", 0, 0, 0, 0, 0, 0);
    ADDSTRING(", label ");
    code_gen_symbol('%', label1);
    ADDSTRING(", label ");
    code_gen_symbol('%', label2);
    ADDSTRING("\n; <label>:");
    code_gen_symbol(0, label1);
    ADDSTRING("\n");
    struct Symbol* symbol1 = load_symbol(expression_func(node->expression));
    ADDSTRING("  br label ");
    code_gen_symbol('%', label3);
    ADDSTRING("\n; <label>:");
    code_gen_symbol(0, label2);
    ADDSTRING("\n");
    struct Symbol* symbol2 = load_symbol(expression_func(node->expression));
    ADDSTRING("  br label ");
    code_gen_symbol('%', label3);
    ADDSTRING("\n; <label>:");
    code_gen_symbol(0, label3);
    ADDSTRING("\n");
    symbol = new_symbol("", symbol2->storage, symbol2->qualifier, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    code_gen_symbol('%', symbol);
    ADDSTRING(" = phi ");
    code_gen_type_specifier(symbol->specifier,0,symbol->length,symbol->stars);
    ADDSTRING(" [ ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol(0, label1);
    ADDSTRING(" ], [ ");
    code_gen_symbol('%', symbol2);
    ADDSTRING(", ");
    code_gen_symbol(0, label2);
    ADDSTRING(" ]\n");
    return symbol;
}


struct Symbol* assignment_expression(struct AssignmentExpression* node)
{
    if (node->type == 0)
        return conditional_expression(node->conditionalExpression);
    // to do
    struct Symbol* orig_symbol;
    struct Symbol* symbol2 = load_symbol(assignment_expression(node->assignmentExpression));
    struct Symbol* symbol1 = unary_expression(node->unaryExpression, &orig_symbol);
    struct Symbol* symbol3 = 0;
    int specifier = symbol1->specifier;

    test_changeable(orig_symbol);
    if (node->assignmentOperator > 1)
    {
        switch (node->assignmentOperator) {
            case 2:
                symbol3 = multiplicative_symbol(symbol1, symbol2, 1);
                break;
            case 3:
                symbol3 = multiplicative_symbol(symbol1, symbol2, 2);
                break;
            case 4:
                symbol3 = multiplicative_symbol(symbol1, symbol2, 3);
                break;
            case 5:
                symbol3 = additive_symbol(symbol1, symbol2, 1);
                break;
            case 6:
                symbol3 = additive_symbol(symbol1, symbol2, 2);
                break;
            case 7:
                symbol3 = shift_symbol(symbol1, symbol2, 1);
                break;
            case 8:
                symbol3 = shift_symbol(symbol1, symbol2, 2);
                break;
            case 9:
                symbol3 = and_symbol(symbol1, symbol2, 1);
                break;
            case 10:
                symbol3 = exclusive_or_symbol(symbol1, symbol2, 1);
                break;
            case 11:
                symbol3 = inclusive_or_symbol(symbol1, symbol2, 1);
                break;
            default:
                break;
        }
    }
    else
        symbol3 = symbol2;
    
    symbol3 = cast_symbol(symbol3, orig_symbol->specifier, orig_symbol->stars);
    ADDSTRING("  store ");
    code_gen_type_specifier(symbol1->specifier,0,symbol1->length,symbol1->stars);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol3);
    ADDSTRING(", ");
    code_gen_type_specifier(symbol1->specifier,0,symbol1->length,symbol1->stars);
    ADDSTRING("* ");
    code_gen_symbol('%',orig_symbol);
    ADDSTRING(", align ");
    int l = len_gen_type_specifier(specifier);
    sprintf(buf, "%d", l);
    ADDSTRING(buf);
    ADDSTRING("\n");
    return symbol3;
}

struct Symbol* expression_func(struct Expression* node)
{
    if (node->type == 1)
        return expression_func(node->expression);
    return assignment_expression(node->assignmentExpression);
}

struct Symbol* constant_expression(struct ConstantExpression* node)
{
    return conditional_expression(node->conditionalExpression);
}