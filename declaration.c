#include "declaration.h"
#include "specify.h"
#include "expression.h"
#include "symbol.h"
#include "assertion.h"

void identifier_list(struct IdentifierList* node, char c)
{
    if (node->type == 1)
    {
        identifier_list(node->identifierList, c);
        ADDSTRING(", ");
    }
    *g_ptr++ = c;
    ADDSTRING(node->identifier);
}

char* direct_declarator(struct DirectDeclarator* node, char c, int *stars, int* length, int isOutput)
{
    struct Symbol* symbol;
    char *ch = 0;
    switch (node->type)
    {
        case 0:
        case 1:
            sprintf(buf, "%c%s", c, node->identifier);
            if (isOutput)
            {
                ADDSTRING(buf);
            }
            return node->identifier;
        case 2:
            ch = direct_declarator(node->directDeclarator, c, stars, length, isOutput);
            *stars = *stars + 1;
            symbol = constant_expression(node->constantExpression);
            test_integer(symbol);
            test_constant(symbol);
            sscanf(symbol->name, "%d", length);
            return ch;
            break;
        case 3:
            //to do: don't know how to do
            break;
        case 4:
            ch = direct_declarator(node->directDeclarator, c, stars, length, isOutput);
            if (isOutput)
            {
                *g_ptr++ = '(';
                *g_ptr = 0;
            }
            parameter_type_list(node->parameterTypeList);
            if (isOutput)
            {
                *g_ptr++ = ')';
                *g_ptr = 0;
            }
            break;
        case 5:
            ch = direct_declarator(node->directDeclarator, c, stars, length, isOutput);
            if (isOutput)
            {
                *g_ptr++ = '(';
                *g_ptr = 0;
            }
            identifier_list(node->identifierList, '%');
            if (isOutput)
            {
                *g_ptr++ = ')';
                *g_ptr = 0;
            }
            break;
        case 6:
            ch = direct_declarator(node->directDeclarator, c, stars, length, isOutput);
            ADDSTRING("()");
            break;
    }
    return ch;
}

char* declarator_func(struct Declarator* declarator, int* qualifier, char c, int *stars, int *length, int isOutput)
{
    if (declarator->type == 0 && isOutput)
    {
//        point_func(declarator->pointer, qualifier);
    }
    return direct_declarator(declarator->directDeclarator, c, stars, length, isOutput);
}

void direct_abstract_declarator(struct DirectAbstractDeclarator* node)
{
    //to do: discard
}

void abstract_declarator(struct AbstractDeclarator* node)
{
    if (node->type != 1)
    {
//        point_func(node->pointer, &qualifier);
    }
    if (node->type > 0)
    {
        direct_abstract_declarator(node->directAbstractDeclarator);
    }
}

void parameter_declaration(struct ParameterDeclaration* node, int *storage, int *qualifier, int *specifier)
{
    int stars = 0, length = 0;
    declaration_specifiers(node->declarationSpecifiers, storage, qualifier, specifier, 0);
    ADDSTRING(" ");
    if (node->type == 0)
    {
        push_arg(gen_new_symbol(node->declarator, '%', *storage, *qualifier, *specifier, &stars, &length, 0));
    }
    else if (node->type == 1)
        abstract_declarator(node->abstractDeclarator);
}

void parameter_list(struct ParameterList* node)
{
    if (node->type == 1)
    {
        parameter_list(node->parameterList);
        ADDSTRING(", ");
    }
    int storage = 0, qualifier = 0, specifier = 0;
    parameter_declaration(node->parameterDeclaration, &storage, &qualifier, &specifier);
}

void parameter_type_list(struct ParameterTypeList* node)
{
    parameter_list(node->parameterList);
    if (node->type == 1)
    {
        ADDSTRING(", ...");
    }
}

struct Symbol* declarator_def(struct Declarator* declarator, char c, int storage, int qualifier, int specifier, int* stars, int *length, int isdefined)
{
    if (c == '%')
        ADDSTRING("  ");
    struct Symbol* symbol = gen_new_symbol(declarator, c, storage, qualifier, specifier, stars, length, 0);
    if (c == '%')
    {
        ADDSTRING(" = alloca ");
    }
    else
    {
        if (!isdefined)
        {
            ADDSTRING(" = common global ");
        }
        else
        {
            ADDSTRING(" = global ");
        }
    }
    code_gen_type_specifier(specifier,0,*length,*stars);
    return symbol;
}

void initializer_func(struct Symbol* orig_symbol, struct Initializer* node, int specifier, char c, int stars)
{
    if (c == '%') {
        //assignment expression to do
        struct Symbol* symbol = assignment_expression(node->assignmentExpression);
        int specifier = orig_symbol->specifier;
        symbol = cast_symbol(symbol, specifier, orig_symbol->stars);
        ADDSTRING("  store ");
        code_gen_type_specifier(specifier,0,0,stars);
        ADDSTRING(" ");
        code_gen_symbol('%', symbol);
        ADDSTRING(", ");
        code_gen_type_specifier(specifier,0,0,stars);
        ADDSTRING("* ");
        code_gen_symbol('%', orig_symbol);
        ADDSTRING(", align ");
        int l = len_gen_type_specifier(specifier);
        sprintf(buf, "%d", l);
        ADDSTRING(buf);
        ADDSTRING("\n");
    } else {
        // to do
        struct Symbol* symbol = assignment_expression(node->assignmentExpression);
        test_constant(symbol);
        symbol = cast_symbol(symbol, specifier, stars);
        ADDSTRING(symbol->name);
    }
}

void init_declarator(struct InitDeclarator* node, char c, int storage, int qualifier, int specifier)
{
    int stars = 0, length = 0;
    struct Symbol* symbol = declarator_def(node->declarator, c, storage, qualifier, specifier, &stars, &length, node->type);
    if (c == '%')
    {
        if (stars == 0)
            sprintf(buf, ", align %d\n", len_gen_type_specifier(specifier));
        else
            sprintf(buf, ", align %d\n", PTR_LENGTH);
        ADDSTRING(buf);
    }
    if (node->type == 1)
    {
        if (c == '@')
            ADDSTRING(" ");
        initializer_func(symbol, node->initializer, specifier, c, stars);
    }
    if (c == '@')
    {
        if (node->type == 0)
        {
            ADDSTRING(" ");
            if (stars)
            {
                ADDSTRING("null");
            }
            else
            {
                ADDSTRING("0");
            }
        }
        if (stars == 0)
            sprintf(buf, ", align %d\n", len_gen_type_specifier(specifier));
        else
            sprintf(buf, ", align %d\n", PTR_LENGTH);
        ADDSTRING(buf);
    }
}

void init_declarator_list(struct InitDeclaratorList* node, int storage, int qualifier, int specifier, char c)
{
    if (node->type == 1)
        init_declarator_list(node->initDeclaratorList, storage, qualifier, specifier, c);
    init_declarator(node->initDeclarator, c, storage, qualifier, specifier);
}

void declaration_func(struct Declaration* node, char c)
{
    int storage = 0, qualifier = 0, specifier = 0;
    declaration_specifiers(node->declarationSpecifiers, &storage, &qualifier, &specifier, 1);
    if (node->type == 1)
    {
        init_declarator_list(node->initDeclaratorList, storage, qualifier, specifier, c);
    }
}

void declaration_list(struct DeclarationList* node, char c)
{
    if (node->type == 1)
    {
        declaration_list(node->declarationList, c);
    }
    declaration_func(node->declaration, c);
}
