#include "statement.h"
#include "expression.h"
#include "specify.h"
#include "declaration.h"
#include "buffer.h"
#include "symbol.h"

void labeled_statement(struct LabeledStatement* node)
{
    // to do
    struct Symbol* label;
    char c;
    switch (node->type) {
        case 0:
            label = new_symbol(node->identifier, 0, 0, 0, 0, 3, 0);
            ADDSTRING("  br label ");
            c = label->name[0];
            label->name[0] = 0;
            code_gen_symbol('%', label);
            ADDSTRING("\n; <label>:");
            code_gen_symbol(0, label);
            ADDSTRING("\n");
            label->name[0] = c;
            statement_func(node->statement);
            break;
        case 1:
        case 2:
        default:
            break;
    }
}

void jump_statement(struct JumpStatement* node)
{
    // to do
    char c;
    struct Symbol* label;
    switch (node->type) {
        case 0:
            label = name2symbol(node->identifier, 3);
            if (!label)
            {
                printf("No label found!\n");
                exit(1);
            }
            ADDSTRING("  br label ");
            c = label->name[0];
            label->name[0] = 0;
            code_gen_symbol('%', label);
            ADDSTRING("\n");
            break;
        case 1:
            break;
            
        case 2:
            break;
            
        case 3:
            ADDSTRING("  ret void\n");
            break;
            
        case 4:
            label = cast_symbol(load_symbol(expression_func(node->expression)), g_specifier, g_stars);
            ADDSTRING("  ret ");
            code_gen_type_specifier(label->specifier, 0, label->length, label->stars);
            ADDSTRING(" ");
            code_gen_symbol('%', label);
            ADDSTRING("\n");
            break;
            
        default:
            break;
    }
}

struct Symbol* expression_statement(struct ExpressionStatement* node)
{
    if (node->type == 1)
        return expression_func(node->expression);
    return 0;
}

void selection_statement(struct SelectionStatement* node)
{
    if (node->type == 0)
    {
        struct Symbol* symbol = convert_to_logic(expression_func(node->expression));
        struct Symbol* label1 = new_symbol("", 0, 0, 0, 0, 3, 0);
        struct Symbol* label2 = new_symbol("", 0, 0, 0, 0, 3, 0);
        ADDSTRING("  br i1 ");
        code_gen_symbol('%',symbol);
        ADDSTRING(", label ");
        code_gen_symbol('%', label1);
        ADDSTRING(", label ");
        code_gen_symbol('%', label2);
        ADDSTRING("\n; <label>:");
        code_gen_symbol(0, label1);
        ADDSTRING("\n");
        statement_func(node->s1);
        ADDSTRING("  br label ");
        code_gen_symbol('%', label2);
        ADDSTRING("\n; <label>:");
        code_gen_symbol(0, label2);
        ADDSTRING("\n");
    } else if (node->type == 1)
    {
        struct Symbol* symbol = convert_to_logic(expression_func(node->expression));
        struct Symbol* label1 = new_symbol("", 0, 0, 0, 0, 3, 0);
        struct Symbol* label2 = new_symbol("", 0, 0, 0, 0, 3, 0);
        struct Symbol* label3 = new_symbol("", 0, 0, 0, 0, 3, 0);
        ADDSTRING("  br i1 ");
        code_gen_symbol('%',symbol);
        ADDSTRING(", label ");
        code_gen_symbol('%', label1);
        ADDSTRING(", label ");
        code_gen_symbol('%', label2);
        ADDSTRING("\n; <label>:");
        code_gen_symbol(0, label1);
        ADDSTRING("\n");
        statement_func(node->s1);
        ADDSTRING("  br label ");
        code_gen_symbol(0, label3);
        ADDSTRING("\n; <label>:");
        code_gen_symbol(0, label2);
        ADDSTRING("\n");
        statement_func(node->s2);
        ADDSTRING("  br label ");
        code_gen_symbol(0, label3);
        ADDSTRING("\n");
    } else
    {
        //switch to do:
    }
}

void iteration_statement(struct IterationStatement* node)
{
    if (node->type == 0)
    {
        struct Symbol* label1 = new_symbol("", 0, 0, 0, 0, 3, 0);
        ADDSTRING("  br label ");
        code_gen_symbol('%', label1);
        ADDSTRING("\n; <label>:");
        code_gen_symbol(0, label1);
        struct Symbol* symbol = convert_to_logic(expression_func(node->expression));
        struct Symbol* label2 = new_symbol("", 0, 0, 0, 0, 3, 0);
        struct Symbol* label3 = new_symbol("", 0, 0, 0, 0, 3, 0);
        ADDSTRING("\n  br i1 ");
        code_gen_symbol('%', symbol);
        ADDSTRING(", label ");
        code_gen_symbol('%', label2);
        ADDSTRING(", label ");
        code_gen_symbol('%', label3);
        ADDSTRING("\n; <label>:");
        code_gen_symbol(0, label2);
        ADDSTRING("\n");
        statement_func(node->statement);
        ADDSTRING("  br label ");
        code_gen_symbol('%', label1);
        ADDSTRING("\n; <label>:");
        code_gen_symbol(0, label3);
        ADDSTRING("\n");
    } else if (node->type == 1)
    {
        struct Symbol* label1 = new_symbol("", 0, 0, 0, 0, 3, 0);
        ADDSTRING("  br label ");
        code_gen_symbol('%', label1);
        ADDSTRING("\n; <label>:");
        code_gen_symbol(0, label1);
        ADDSTRING("\n");
        statement_func(node->statement);
        struct Symbol* label2 = new_symbol("", 0, 0, 0, 0, 3, 0);
        ADDSTRING("  br label ");
        code_gen_symbol('%', label2);
        ADDSTRING("\n; <label>:");
        code_gen_symbol(0, label2);
        ADDSTRING("\n");
        struct Symbol* symbol = convert_to_logic(expression_func(node->expression));
        struct Symbol* label3 = new_symbol("", 0, 0, 0, 0, 3, 0);
        ADDSTRING("  br i1 ");
        code_gen_symbol('%', symbol);
        ADDSTRING(", label ");
        code_gen_symbol('%', label1);
        ADDSTRING(", label ");
        code_gen_symbol('%', label3);
        ADDSTRING("\n; <label>:");
        code_gen_symbol(0, label3);
        ADDSTRING("\n");
    } else
    {
        expression_statement(node->s1);
        struct Symbol* label1 = new_symbol("", 0, 0, 0, 0, 3, 0);
        ADDSTRING("  br label ");
        code_gen_symbol('%', label1);
        ADDSTRING("\n; <label>:");
        code_gen_symbol(0, label1);
        ADDSTRING("\n");
        struct Symbol* condition = expression_statement(node->s2);
        struct Symbol* label2 = new_symbol("", 0, 0, 0, 0, 3, 0);
        struct Symbol* label3 = new_symbol("", 0, 0, 0, 0, 3, 0);
        if (condition)
        {
            condition = convert_to_logic(condition);
            ADDSTRING("  br i1 ");
            code_gen_symbol('%', condition);
            ADDSTRING(", label ");
            code_gen_symbol('%', label2);
            ADDSTRING(", label ");
            code_gen_symbol('%', label3);
            ADDSTRING("\n");
        }
        ADDSTRING("; <label>:");
        code_gen_symbol(0, label2);
        ADDSTRING("\n");
        statement_func(node->statement);
        if (node->type > 2)
            expression_func(node->expression);
        ADDSTRING("  br label ");
        code_gen_symbol('%', label1);
        ADDSTRING("\n;<label>:");
        code_gen_symbol(0, label3);
        ADDSTRING("\n");
    }
}

void statement_func(struct Statement* node)
{
    switch (node->type)
    {
        case 0:
            labeled_statement(node->labeledStatement);
            break;
        case 1:
            push_domain();
            compound_statement(node->compoundStatement);
            pop_domain(0);
            break;
        case 2:
            expression_statement(node->expressionStatement);
            break;
        case 3:
            selection_statement(node->selectionStatement);
            break;
        case 4:
            iteration_statement(node->iterationStatement);
            break;
        case 5:
            jump_statement(node->jumpStatement);
            break;
    }
}

void statement_list(struct StatementList* node)
{
    if (node->type == 1)
        statement_list(node->statementList);
    statement_func(node->statement);
}

void compound_statement(struct CompoundStatement* node)
{
    if (node->type == 0)
        return;
    if (node->type != 1)
        declaration_list(node->declarationList, '%');
    if (node->type != 2)
        statement_list(node->statementList);
}

void function_definition(struct FunctionDefinition* node)
{
    // to do
    int storage = 0, specifier = 0, ret_qualifier = 0, point_quality = 0, stars = 0;
    ADDSTRING("\ndefine ");
    declaration_specifiers(node->declarationSpecifiers, &storage, &ret_qualifier, &specifier, 0);
    ADDSTRING(" ");
    push_domain();
    declarator_func(node->declarator, &point_quality, '@', &stars, 0, 1);
    ADDSTRING(" nounwind ssp uwtable{\n");
    g_specifier = specifier;
    g_stars = stars;
    // to do: declaration_list
    compound_statement(node->compoundStatement);
    ADDSTRING("}\n");
    pop_domain(1);
}

void external_declaration(struct ExternalDeclaration* node)
{
    if (node->type == 0)
        function_definition(node->functionDefinition);
    else
        declaration_func(node->declaration, '@');
}

void translation_unit(struct TranslationUnit* node)
{
    if (node->type == 1)
        translation_unit(node->translationUnit);
    external_declaration(node->externalDeclaration);
}

void translation_unit_begin(struct TranslationUnit* node)
{
    initialize_buffer();
    initialize_symbols();
    if (node->type == 1)
        translation_unit(node->translationUnit);
    external_declaration(node->externalDeclaration);
    code_gen();
}
