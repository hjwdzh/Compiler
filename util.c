#include "util.h"
#include "declaration.h"

char *g_ptr = 0;
char buf[1000] = {0};
int g_specifier = 0, g_stars = 0;

void code_gen_with_header(char *filename)
{
    printf("; ModuleID = \'%s\'\n", filename);
    printf("target datalayout = \"e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128\"\n");
    printf("target triple = \"%s\"\n\n", TARGET_TRIPLE);
}

int len_gen_type_specifier(int val)
{
    if (val & 0x01)
        return 0;
    if (val & 0x02) {
        return 0;
    }
    if (val & 0x04) {
        return 1;
    }
    if (val & 0x08) {
        return 2;
    }
    if (val & 0x10) {
        return 4;
    }
    if (val & 0x20) {
        return 8;
    }
    if (val & 0x40) {
       return 4;
    }
    if (val & 0x80) {
       return 8;
    }
/*
        case 8:
            // to do: union or struct
            break;
            
        case 9:
            // to do: enum_specifier
            break;
            
        case 10:
*/            // to do: typename
            
    return 0;
}

const char* code_gen_type_specifier(int val, int isnsw, int length, int stars)
{
    int i,j;
    sprintf(buf, "[%d x ", length);
    if (length > 0)
        ADDSTRING(buf);
    if (isnsw && (val & (1 << 9)) == 0)
        ADDSTRING("nsw ");
    for (j = 0; j < 13; ++j)
        if ((val & (1 << j)) > 0)
        {
    switch (j) {
        case 0:
            ADDSTRING("i1");
            if (length > 0)
            {
                ADDSTRING("]");
            }
            for (i = 0; i < stars; ++i)
            {
                ADDSTRING("*");
            }
            return "i1";
        case 1:
            ADDSTRING("void");
            if (length > 0)
            {
                ADDSTRING("]");
            }
            for (i = 0; i < stars; ++i)
            {
                ADDSTRING("*");
            }
            return "void";
            
        case 2:
            ADDSTRING("i8");
            if (length > 0)
            {
                ADDSTRING("]");
            }
            for (i = 0; i < stars; ++i)
            {
                ADDSTRING("*");
            }
            return "i8";
            
        case 3:
            ADDSTRING("i16");
            if (length > 0)
            {
                ADDSTRING("]");
            }
            for (i = 0; i < stars; ++i)
            {
                ADDSTRING("*");
            }
            return "i16";
            
        case 4:
            ADDSTRING("i32");
            if (length > 0)
            {
                ADDSTRING("]");
            }
            for (i = 0; i < stars; ++i)
            {
                ADDSTRING("*");
            }
            return "i32";
            
        case 5:
            ADDSTRING("i64");
            if (length > 0)
            {
                ADDSTRING("]");
            }
            for (i = 0; i < stars; ++i)
            {
                ADDSTRING("*");
            }
            return "i64";
            
        case 6:
            ADDSTRING("float");
            if (length > 0)
            {
                ADDSTRING("]");
            }
            for (i = 0; i < stars; ++i)
            {
                ADDSTRING("*");
            }
            return "float";
            
        case 7:
            ADDSTRING("double");
            if (length > 0)
            {
                ADDSTRING("]");
            }
            for (i = 0; i < stars; ++i)
            {
                ADDSTRING("*");
            }
            return "double";
            
        case 8:
            break;
            
        case 9:
            break;
            
        case 10:
            // to do: union or struct
            break;
            
        case 11:
            // to do: enum_specifier
            break;
            
        case 12:
            // to do: typename
            
        default:
            break;
    }
        }
    return "";
}

int numPoint(struct Pointer* node)
{
    if (node->type >= 2)
        return 1 + numPoint(node->pointer);
    return 1;
}

void code_gen_symbol(char c, struct Symbol* symbol)
{
    if (symbol->depth == 0)
        c = '@';
    if (c > 0 && symbol->type != 2)
        *g_ptr++ = c;
    if (symbol->name && symbol->name[0] != 0)
    {
        ADDSTRING(symbol->name);
    }
    if (symbol->type != 2 && (!(symbol->name && strlen(symbol->name)) || symbol->prefix > 1))
    {
        sprintf(buf, "%d", symbol->prefix - (symbol->name && strlen(symbol->name)));
        ADDSTRING(buf);
    }
}

struct Symbol* gen_new_symbol(struct Declarator* declarator, char c, int storage, int qualifier, int specifier, int* stars, int *length, int isOutput, int isParameter)
{
    char* ch;
    if (declarator->type == 0)
        *stars = numPoint(declarator->pointer);
    if (isOutput)
    {
        for (int i = 0; i < *stars; ++i)
        {
            *g_ptr++ = '*';
        }
        *g_ptr = 0;
    }
    
    ch = declarator_func(declarator, &specifier, c, stars, length, isOutput);
    struct Symbol* symbol = name2symbol(ch, 0);
    if (c == '@' && symbol)
    {
        if (storage != symbol->storage || qualifier != symbol->qualifier || specifier != symbol->specifier
            || *stars != symbol->stars || *length != symbol->length || current_type != symbol->type)
        {
            printf("symbol conflict!\n");
            exit(0);
        }
    }
    else
    {
        symbol = new_symbol(ch, storage, qualifier, specifier, *stars, current_type, isParameter ? 0 : *length);
        current_type = 0;
    }
    if (isOutput)
        ADDSTRING(" ");
    code_gen_symbol(c, symbol);
    return symbol;
}

int len_gen_type_name(struct TypeName* node)
{
    int specifier, stars;
    typename2specifier(node, &specifier, &stars);
    if (stars == 0)
        return len_gen_type_specifier(specifier);
    return PTR_LENGTH;
}

int direct2stars(struct DirectAbstractDeclarator* node)
{
    int res = 0;
    if (node->type == 0)
        return abstract2stars(node->abstractDeclarator);
    res += (node->type < 5);
    if (node->type != 5 && node->type != 6)
        res += direct2stars(node->directAbstractDeclarator);
    return res;
}

int abstract2stars(struct AbstractDeclarator* node)
{
    int res = (node->type != 1);
    if (node->type > 0)
    {
        res += direct2stars(node->directAbstractDeclarator);
    }
    return res;
}

void typename2specifier(struct TypeName* node, int *specifier, int *stars)
{
    struct SpecifierQualifierList* ptr = node->specifierQualifierList;
    while ((ptr->type & 0x01) == 0)
    {
        if (ptr->type < 2)
        {
            *specifier |= (1 << ptr->typeSpecifier);
        }
        ptr = ptr->specifierQualifierList;
    }
    if (ptr->type < 2)
    {
        *specifier |= (1 << ptr->typeSpecifier);
    }
    if (node->type == 1)
    {
        *stars = abstract2stars(node->abstractDeclarator);
    }
}

void code_gen_standard_declaration()
{
    printf("declare i32 @printf(i8*, ...)\n");
    printf("declare i32 @scanf(i8*, ...)\n");
    printf("declare i8* @malloc(i64)\n");
    printf("declare i32 @free(...)\n");
}