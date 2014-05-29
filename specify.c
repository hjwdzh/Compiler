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
                ch = code_gen_type_specifier(node->typeSpecifier, 0, 0, isNotOutput);
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

