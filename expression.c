#include "expression.h"

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
    struct Symbol* symbol = 0;
    struct Symbol* symbol1 = 0;
    int l;
    switch (node->type) {
        case 0:
            symbol = name2symbol(node->identifier, 0);
            symbol1 = new_symbol("", symbol->storage, symbol->qualifier, symbol->specifier, symbol->stars, 0, symbol->length);
            ADDSTRING("  ");
            code_gen_symbol('%', symbol1);
            ADDSTRING(" = load ");
            code_gen_type_specifier(symbol1->specifier, 0, symbol1->length, symbol1->stars);
            ADDSTRING("* ");
            code_gen_symbol('%', symbol);
            ADDSTRING(", align ");
            l = len_gen_type_specifier(symbol1->specifier);
            sprintf(buf, "%d\n", l);
            ADDSTRING(buf);
            *orig_symbol = symbol;
            return symbol1;
        case 1://INT
            sprintf(buf, "%d", node->iValue);
            *orig_symbol = new_symbol(buf, 0, 1, 1 << 4, 0, 2, 0);
            return *orig_symbol;
        case 2://char
            sprintf(buf, "%d", (int)node->cValue);
            *orig_symbol = new_symbol(buf, 0, 1, 1 << 2, 0, 2, 0);
            return *orig_symbol;
        case 3://f
            sprintf(buf, "%f", node->fValue);
            return new_symbol(buf, 0, 1, 1 << 6, 0, 2, 0);
        case 4://d
            sprintf(buf, "%lf", node->dValue);
            *orig_symbol = new_symbol(buf, 0, 1, 1 << 7, 0, 2, 0);
            return *orig_symbol;
        case 5:
            *orig_symbol = new_symbol(node->literal, 0, 1, 1 << 2, 1, 2, 0);
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
    int i;
    switch (node->type) {
        case 0:
            return primary_expression(node->primaryExpression, orig_symbol);
        case 1:
            symbol = postfix_expression(node->postfixExpression, orig_symbol);
            ref = expression_func(node->expression);
            *orig_symbol = new_symbol("", symbol->storage, symbol->qualifier, symbol->specifier, symbol->stars - 1, 0, 0);
            code_gen_symbol('%', *orig_symbol);
            ADDSTRING(" = getelementptr inbounds ");
            code_gen_type_specifier(symbol->specifier, 0, symbol->length, symbol->stars);
            for (i = 0; i < symbol->stars; ++i)
                ADDSTRING("*");
            ADDSTRING(" ");
            if (symbol->depth == 0)
                code_gen_symbol('@', symbol);
            else
                code_gen_symbol('%', symbol);
            ADDSTRING(", i32 0, i64 ");
            code_gen_symbol(0, ref);
            ADDSTRING("\n");
            return *orig_symbol;
        case 2:
        case 3:
            if (node->type == 3)
            {
                argument_expression_list(node->argumentExpressionList);
            }
            symbol = postfix_expression(node->postfixExpression, orig_symbol);
            newSymbol = new_symbol("", symbol->storage, symbol->qualifier, symbol->specifier, symbol->stars, 0, symbol->length);
            code_gen_symbol('%', symbol);
            ADDSTRING(" = call ");
            code_gen_type_specifier(symbol->specifier, 0, symbol->length, symbol->stars);
            ADDSTRING(" ");
            if (symbol->depth == 0)
                code_gen_symbol('@', symbol);
            else
                code_gen_symbol('%', symbol);
            ADDSTRING("(");
            if (node->type == 3)
            {
                pop_arg();
            }
            ADDSTRING(")");
            *orig_symbol = symbol;
            return newSymbol;
        case 4:
        case 5:
            // to do: struct
            return 0;
        case 6:
        case 7:
            symbol = postfix_expression(node->postfixExpression, orig_symbol);
            symbol1 = new_symbol("", symbol->storage, symbol->qualifier, symbol->specifier, symbol->stars, 0, symbol->length);
            code_gen_symbol('%', symbol1);
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
            return symbol;
        default:
            return 0;
    }
}

struct Symbol* unary_expression(struct UnaryExpression* node, struct Symbol** orig_symbol)
{
    int i, len;
    struct Symbol *symbol, *symbol1 = NULL;
    switch (node->type) {
        case 0:
            return postfix_expression(node->postfixExpression, orig_symbol);
            
        case 1:
        case 2:
            symbol = unary_expression(node->unaryExpression, orig_symbol);
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
            code_gen_type_specifier(symbol->specifier,1,symbol->length, symbol->stars);
            ADDSTRING(" ");
            code_gen_symbol('%', symbol1);
            ADDSTRING(", ");
            code_gen_type_specifier(symbol->specifier,1,symbol->length, symbol->stars);
            ADDSTRING("* ");
            code_gen_symbol('%', *orig_symbol);
            ADDSTRING(", align ");
            int l = len_gen_type_specifier(symbol->specifier);
            sprintf(buf, "%d", l);
            ADDSTRING(buf);
            ADDSTRING("\n");
            break;
            
        case 3:
            symbol = cast_expression(node->castExpression);
            switch (node->unaryOperator) {
                case 1:
                    symbol1 = symbol;
                    break;
                case 2:
                    symbol1 = new_symbol("", symbol->storage, symbol->qualifier, symbol->specifier, symbol->stars + 1, 0, symbol->length);
                    ADDSTRING("  ");
                    code_gen_symbol('%', symbol1);
                    ADDSTRING(" = load ");
                    code_gen_symbol('%', symbol);
                    for (i = 0; i < symbol1->stars; ++i)
                        ADDSTRING("*");
                    ADDSTRING(" ");
                    code_gen_symbol('%', symbol);
                    ADDSTRING(", align 8\n");
                    break;
                case 3:
                    symbol1 = symbol;
                    break;
                case 4:
                    symbol1 = new_symbol("", symbol->storage, symbol->qualifier, symbol->specifier, symbol->stars - 1, 0, 0);
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
                    break;
                case 5:
                    symbol1 = new_symbol("", symbol->storage, symbol->qualifier, symbol->specifier, symbol->stars, 0, symbol->length);
                    ADDSTRING("  ");
                    code_gen_symbol('%', symbol1);
                    ADDSTRING(" = xor ");
                    code_gen_type_specifier(symbol->specifier,1, symbol->length, symbol->stars);
                    ADDSTRING(" ");
                    code_gen_symbol('%', symbol);
                    ADDSTRING(", -1");
                    ADDSTRING("\n");
                    break;
                case 6:
                    symbol1 = new_symbol("", symbol->storage, symbol->qualifier, symbol->specifier, symbol->stars, 0, symbol->length);
                    ADDSTRING("  ");
                    code_gen_symbol('%', symbol1);
                    ADDSTRING(" = xor i1 ");
                    ADDSTRING(" ");
                    code_gen_symbol('%', symbol);
                    ADDSTRING(", true");
                    symbol1 = new_symbol("", 0, 1, 4, 0, 0, 0);
                    symbol = symbol1;
                    ADDSTRING("  ");
                    code_gen_symbol('%', symbol1);
                    ADDSTRING(" = zext it ");
                    code_gen_symbol('%', symbol);
                    ADDSTRING(" to i32\n");
                    break;
                default:
                    break;
            }
            break;
            
        case 4:
            symbol = unary_expression(node->unaryExpression, orig_symbol);
            len = len_gen_type_specifier(symbol->specifier);
            sprintf(buf, "%d", len);
            symbol1 = new_symbol(buf, 0, 1, 4, 0, 2, 0);
            break;
            
        case 5:
            len = len_gen_type_name(node->typeName);
            sprintf(buf, "%d", len);
            symbol1 = new_symbol(buf, 0, 1, 4, 0, 2, 0);
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
    return cast_expression(node->castExpression);
}

struct Symbol* multiplicative_expression(struct MultiplicativeExpression* node)
{
    if (node->type == 0)
        return cast_expression(node->castExpression);
    struct Symbol* symbol1 = multiplicative_expression(node->multiplicativeExpression);
    struct Symbol* symbol2 = cast_expression(node->castExpression);
    struct Symbol* symbol3 = new_symbol("", symbol2->storage, symbol2->qualifier, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    if ((symbol1->specifier & (3 << 6)) != 0)
    {
        ADDSTRING(" = f");
    }
    else
    {
        if (node->type == 3)
        {
            if ((symbol1->specifier & (1 << 9)) > 0)
            {
                ADDSTRING(" = u");
            }
            else
            {
                ADDSTRING(" = s");
            }
        }
        else
        {
            ADDSTRING(" = ");
        }
    }
    if (node->type == 1)
    {
        ADDSTRING("mul ");
    }
    else if (node->type == 2)
    {
        ADDSTRING("div ");
    }
    else
    {
        ADDSTRING("rem ");
    }
    code_gen_type_specifier(symbol1->specifier,1,symbol1->length,symbol1->stars);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol('%', symbol2);
    ADDSTRING("\n");
    return symbol3;
}

struct Symbol* additive_expression(struct AdditiveExpression* node)
{
    if (node->type == 0)
        return multiplicative_expression(node->multiplicativeExpression);
    struct Symbol* symbol1 = additive_expression(node->additiveExpression);
    struct Symbol* symbol2 = multiplicative_expression(node->multiplicativeExpression);
    struct Symbol* symbol3 = new_symbol("", symbol2->storage, symbol2->qualifier, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    if ((symbol3->specifier & (3 << 6)) != 0)
    {
        ADDSTRING(" = f");
    }
    else
    {
        ADDSTRING(" = ");
    }
    if (node->type == 1)
    {
        ADDSTRING("sub ");
    }
    else
    {
        ADDSTRING("add ");
    }
    code_gen_type_specifier(symbol3->specifier,1,symbol3->length, symbol3->storage);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol('%', symbol2);
    ADDSTRING("\n");
    return symbol3;
}

struct Symbol* shift_expression(struct ShiftExpression* node)
{
    if (node->type == 0)
        return additive_expression(node->additiveExpression);
    struct Symbol* symbol1 = shift_expression(node->shiftExpression);
    struct Symbol* symbol2 = additive_expression(node->additiveExpression);
    struct Symbol* symbol3 = new_symbol("", symbol2->storage, symbol2->qualifier, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    if ((symbol1->specifier & (1 << 9)) > 0)
    {
        ADDSTRING(" = lsh ");
    }
    else
    {
        ADDSTRING(" = ash ");
    }
    if (node->type == 1)
    {
        ADDSTRING("l");
    }
    else
    {
        ADDSTRING("r");
    }
    code_gen_type_specifier(symbol3->specifier,0,symbol3->length,symbol3->stars);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol('%', symbol2);
    ADDSTRING("\n");
    return symbol3;
}

struct Symbol* relational_expression(struct RelationalExpression* node)
{
    if (node->type == 0)
        return shift_expression(node->shiftExpression);
    struct Symbol* symbol1 = relational_expression(node->relationalExpression);
    char c = 's';
    if ((symbol1->specifier & (1 << 9)) > 0)
        c = 'u';
    struct Symbol* symbol2 = shift_expression(node->shiftExpression);
    struct Symbol* symbol3 = new_symbol("", symbol2->storage, symbol2->qualifier, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    if ((symbol2->specifier & (3 << 6)) != 0)
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
    code_gen_type_specifier(symbol3->specifier,0, symbol3->length, symbol3->stars);
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
    struct Symbol* symbol1 = equality_expression(node->equalityExpression);
    struct Symbol* symbol2 = relational_expression(node->relationalExpression);
    struct Symbol* symbol3 = new_symbol("", symbol2->storage, symbol2->qualifier, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    if ((symbol3->specifier & (3 << 6)) != 0)
    {
        if (node->type == 1)
        {
            ADDSTRING(" = fcmp oeq");
        }
        else
        {
            ADDSTRING(" = fcmp one");
        }
    }
    else {
        if (node->type == 1)
        {
            ADDSTRING(" = icmp eq ");
        }
        else
        {
            ADDSTRING(" = icmp ne ");
        }
    }
    code_gen_type_specifier(symbol3->specifier,0, symbol3->length, symbol3->stars);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol('%', symbol2);
    ADDSTRING("\n");
    return symbol3;
}

struct Symbol* and_expression(struct AndExpression* node)
{
    if (node->type == 0)
        return equality_expression(node->equalityExpression);
    struct Symbol* symbol1 = and_expression(node->andExpression);
    struct Symbol* symbol2 = equality_expression(node->equalityExpression);
    struct Symbol* symbol3 = new_symbol("", symbol2->storage, symbol2->qualifier, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    ADDSTRING(" = and ");
    code_gen_type_specifier(symbol3->specifier,0,symbol3->length,symbol3->stars);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol('%', symbol2);
    ADDSTRING("\n");
    return symbol3;
}

struct Symbol* exclusive_or_expression(struct ExclusiveOrExpression* node)
{
    if (node->type == 0)
        return and_expression(node->andExpression);
    struct Symbol* symbol1 = exclusive_or_expression(node->exclusiveOrExpression);
    struct Symbol* symbol2 = and_expression(node->andExpression);
    struct Symbol* symbol3 = new_symbol("", symbol2->storage, symbol2->qualifier, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    ADDSTRING(" = xor ");
    code_gen_type_specifier(symbol3->specifier,0,symbol3->length,symbol3->stars);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol('%', symbol2);
    ADDSTRING("\n");
    return symbol3;
}

struct Symbol* inclusive_or_expression(struct InclusiveOrExpression* node)
{
    if (node->type == 0)
        return exclusive_or_expression(node->exclusiveOrExpression);
    struct Symbol* symbol1 = inclusive_or_expression(node->inclusiveOrExpression);
    struct Symbol* symbol2 = exclusive_or_expression(node->exclusiveOrExpression);
    struct Symbol* symbol3 = new_symbol("", symbol2->storage, symbol2->qualifier, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    ADDSTRING(" = or ");
    code_gen_type_specifier(symbol3->specifier,0,symbol3->length,symbol3->stars);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol('%', symbol2);
    ADDSTRING("\n");
    return symbol3;
}

struct Symbol* logical_and_expression(struct LogicalAndExpression* node)
{
    if (node->type == 0)
        return inclusive_or_expression(node->inclusiveOrExpression);
    struct Symbol* symbol1 = logical_and_expression(node->logicalAndExpression);
    struct Symbol* symbol2 = inclusive_or_expression(node->inclusiveOrExpression);
    struct Symbol* symbol3 = new_symbol("", symbol2->storage, symbol2->qualifier, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    ADDSTRING(" = and ");
    code_gen_type_specifier(symbol3->specifier,0,symbol3->length,symbol3->stars);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol('%', symbol2);
    ADDSTRING("\n");
    return symbol3;
}

struct Symbol* logical_or_expression(struct LogicalOrExpression* node)
{
    if (node->type == 0)
        return logical_and_expression(node->logicalAndExpression);
    struct Symbol* symbol1 = logical_or_expression(node->logicalOrExpression);
    struct Symbol* symbol2 = logical_and_expression(node->logicalAndExpression);
    struct Symbol* symbol3 = new_symbol("", symbol2->storage, symbol2->qualifier, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    ADDSTRING(" = or ");
    code_gen_type_specifier(symbol3->specifier,0,symbol3->length,symbol3->stars);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol('%', symbol2);
    ADDSTRING("\n");
    return symbol3;
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
    code_gen_symbol('%', label1);
    ADDSTRING("\n; <label>:");
    code_gen_symbol(0, label1);
    ADDSTRING("\n");
    struct Symbol* symbol1 = expression_func(node->expression);
    ADDSTRING("  br label ");
    code_gen_symbol('%', label3);
    ADDSTRING("\n; <label>:");
    code_gen_symbol(0, label2);
    ADDSTRING("\n");
    struct Symbol* symbol2 = expression_func(node->expression);
    ADDSTRING("  br label ");
    code_gen_symbol('%', label3);
    ADDSTRING("\n; <label>:");
    code_gen_symbol(0, label3);
    ADDSTRING("\n");
    symbol = new_symbol("", symbol2->storage, symbol2->qualifier, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    code_gen_symbol('%', symbol);
    ADDSTRING(" = phi ");
    code_gen_type_specifier(symbol->specifier,1,symbol->length,symbol->stars);
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
    struct Symbol* symbol2 = assignment_expression(node->assignmentExpression);
    struct Symbol* symbol1 = unary_expression(node->unaryExpression, &orig_symbol);
    struct Symbol* symbol3 = 0;
    int specifier = symbol1->specifier;
    
    if (node->assignmentOperator > 1)
    {
        symbol3 = new_symbol("", symbol2->storage, symbol2->qualifier, symbol2->specifier, symbol2->stars, 0, symbol2->length);
        ADDSTRING("  ");
        code_gen_symbol('%', symbol3);
        if ((specifier & (3 << 6)) != 0)
        {
            ADDSTRING(" = f");
        }
        else
        {
            ADDSTRING(" = ");
        }
        switch (node->assignmentOperator) {
            case 2:
                ADDSTRING("mul");
                break;
            case 3:
                ADDSTRING("div");
                break;
            case 4:
                if ((symbol1->specifier & (1 << 9)) > 0)
                {
                    ADDSTRING("urem");
                }
                else
                {
                    ADDSTRING("srem");
                }
                break;
            case 5:
                ADDSTRING("add");
                break;
            case 6:
                ADDSTRING("sub");
                break;
            case 7:
                ADDSTRING("shl");
                break;
            case 8:
                if ((symbol1->specifier & (1 << 9)) > 0)
                {
                    ADDSTRING("lshr");
                }
                else
                {
                    ADDSTRING("ashr");
                }
                break;
            case 9:
                ADDSTRING("and");
                break;
            case 10:
                ADDSTRING("xor");
                break;
            case 11:
                ADDSTRING("or");
                break;
            default:
                break;
        }
        ADDSTRING(" ");
        code_gen_type_specifier(symbol1->specifier,0,symbol1->length,symbol1->stars);
        ADDSTRING(" ");
        code_gen_symbol('%', symbol1);
        ADDSTRING(", ");
        code_gen_symbol('%', symbol2);
        ADDSTRING("\n");
    }
    else
        symbol3 = symbol2;
    
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
