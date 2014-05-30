#include "declaration.h"
#include "specify.h"
#include "expression.h"

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

char* direct_declarator(struct DirectDeclarator* node, char c, int isOutput)
{
    switch (node->type)
    {
        case 0:
            sprintf(buf, "%c%s", c, node->identifier);
            if (isOutput)
            {
                ADDSTRING(buf);
            }
            return node->identifier;
        case 1:
            //to do: don't know how to do
            break;
        case 2:
            //to do: don't know how to do
            break;
        case 3:
            //to do: don't know how to do
            break;
        case 4:
            direct_declarator(node->directDeclarator, c, isOutput);
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
            direct_declarator(node->directDeclarator, c, isOutput);
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
            direct_declarator(node->directDeclarator, c, isOutput);
            ADDSTRING("()");
            break;
    }
    return 0;
}

char* declarator_func(struct Declarator* declarator, int* qualifier, char c, int isOutput)
{
    if (declarator->type == 0 && isOutput)
    {
//        point_func(declarator->pointer, qualifier);
    }
    return direct_declarator(declarator->directDeclarator, c, isOutput);
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
    int stars;
    declaration_specifiers(node->declarationSpecifiers, storage, qualifier, specifier, 0);
    if (node->type == 1)
    {
        gen_new_symbol(node->declarator, '%', *storage, *qualifier, *specifier, &stars, 1, 0);
    }
    else if (node->type == 2)
        abstract_declarator(node->abstractDeclarator);
}

void parameter_list(struct ParameterList* node)
{
    if (node->type == 1)
    {
        parameter_list(node->parameterList);
        ADDSTRING(", ");
    }
    int storage, qualifier, specifier;
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

struct Symbol* declarator_def(struct Declarator* declarator, char c, int storage, int qualifier, int specifier, int* stars)
{
    int i;
    ADDSTRING("  ");
    struct Symbol* symbol = gen_new_symbol(declarator, c, storage, qualifier, specifier, stars, 0, 0);
    ADDSTRING(" = alloca ");
    code_gen_type_specifier(specifier,0,0,0);
    for (i = 0; i < *stars; ++i)
    {
        *g_ptr++ = '*';
    }
    *g_ptr = 0;
    if (*stars == 0)
        sprintf(buf, ", align %d\n", len_gen_type_specifier(specifier));
    else
        sprintf(buf, ", align %d\n", PTR_LENGTH);
    ADDSTRING(buf);
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
    }
}

void init_declarator(struct InitDeclarator* node, char c, int storage, int qualifier, int specifier)
{
    int stars = 0;
    struct Symbol* symbol = declarator_def(node->declarator, c, storage, qualifier, specifier, &stars);
    if (node->type == 1)
    {
        initializer_func(symbol, node->initializer, specifier, c, stars);
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
