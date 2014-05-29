#include "specify.h"

const char* declaration_specifiers(struct DeclarationSpecifiers* node, int* storage, int* qualifier, int* specifier, int isNotOutput)
{
    const char* ch = 0;
    if (node->type <= 1)
    {
        *storage |= (1 << node->storageClassSpecifier);
    }
    else
        if (node->type <= 3)
        {
            *specifier |= (1 << node->typeSpecifier);
            if (isNotOutput == 0)
                ch = code_gen_type_specifier(*specifier, 0, 0, isNotOutput);
        }
        else
        {
            *qualifier |= (1 << node->typeQualifier);
        }
    if ((node->type & 1 )> 0)
    {
        declaration_specifiers(node->declarationSpecifiers, storage, qualifier, specifier, isNotOutput);
    }
    return ch;
}

void type_qualifier_list(struct TypeQualifierList* node, int *qualifier)
{
    *qualifier |= (1 << node->typeQualifier);
    if (node->type == 1)
        type_qualifier_list(node->typeQualifierList, qualifier);
}

int parse_type(int specifier){
    int i = 0;
    while (!(specifier & (1 << i)))
        ++i;
    return i;
}

struct Symbol* cast_symbol(struct Symbol* symbol, int specifier, int stars)
{
    if (symbol->stars != stars)
    {
        printf("Type Conflict!\n");
        exit(1);
    }
    int orig = parse_type(symbol->specifier);
    int cur = parse_type(specifier);
    if (orig == cur)
        return symbol;
    struct Symbol* newsymbol = 0;
    if (symbol->type == 2 && (orig <= 5) == (cur <= 5))
    {
        if (specifier > symbol->specifier)
        {
            symbol->specifier = specifier;
        }
        return symbol;
    }
    ADDSTRING("  ");
    newsymbol = new_symbol("", 0, 0, specifier, symbol->stars, 0, symbol->length);
    code_gen_symbol('%', newsymbol);
    ADDSTRING(" = ");
    if ((orig <= 5) == (cur <= 5))
    {
        
        if (orig < cur)
        {
            if (orig > 5)
            {
                ADDSTRING("fpext");
            }
            else {
                if (symbol->specifier & (1 << 9))
                {
                    ADDSTRING("uext ");
                }
                else
                {
                    ADDSTRING("sext ");
                }
            }
        }
        else
        {
            if (orig > 5)
                ADDSTRING("fp");
            ADDSTRING("trunc")
        }
    }
    else
    {
        if (orig > 5)
        {
            ADDSTRING("fpto");
            if (specifier & (1 << 9))
            {
                ADDSTRING("ui");
            }
            else
            {
                ADDSTRING("si");
            }
        }
        else
        {
            if (symbol->specifier & (1 << 9))
            {
                ADDSTRING("ui");
            }
            else
            {
                ADDSTRING("si");
            }
            ADDSTRING("tofp");
        }
    }
    ADDSTRING(" ");
    code_gen_type_specifier(symbol->specifier, 0, symbol->length, symbol->stars);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol);
    ADDSTRING(" to ");
    code_gen_type_specifier(specifier, 0, symbol->length, symbol->stars);
    ADDSTRING("\n");
    return newsymbol;
}

