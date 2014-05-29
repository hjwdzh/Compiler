#include "util.h"
#include "declaration.h"

char *g_ptr = 0;
char buf[20] = {0};

void code_gen_with_header(char *filename)
{
    printf("; ModuleID = \'%s\'\n", filename);
    printf("target datalayout = \"e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128\"\n");
    printf("target triple = \"%s\"\n\n", TARGET_TRIPLE);
}

int len_gen_type_specifier(int val)
{
    switch (val) {
        case 1:
            return 0;
            break;
            
        case 2:
            return 1;
            break;
            
        case 3:
            return 2;
            break;
            
        case 4:
            return 4;
            break;
            
        case 5:
            return 8;
            break;
            
        case 6:
            return 4;
            break;
            
        case 7:
            return 8;
            break;
            
        case 8:
            // to do: union or struct
            break;
            
        case 9:
            // to do: enum_specifier
            break;
            
        case 10:
            // to do: typename
            
        default:
            break;
    }
    return 0;
}

const char* code_gen_type_specifier(int val, int isnsw, int length, int stars)
{
    int i;
    sprintf(buf, "[%d x ", length);
    if (length > 0)
        ADDSTRING(buf);
    if (isnsw && (val & (1 << 9)) == 0)
        ADDSTRING("nsw ");
    switch (val) {
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
    if (c > 0 && symbol->type != 2)
        *g_ptr++ = c;
    sprintf(buf, "%d", symbol->prefix);
    ADDSTRING(buf);
}

struct Symbol* gen_new_symbol(struct Declarator* declarator, char c, int storage, int qualifier, int specifier, int* stars, int length, int print_star)
{
    char* ch;
    if (declarator->type == 0)
        *stars = numPoint(declarator->pointer);
    if (print_star)
    {
        for (int i = 0; i < *stars; ++i)
        {
            *g_ptr++ = '*';
        }
        *g_ptr = 0;
    }
    ch = declarator_func(declarator, &specifier, c, 0);
    struct Symbol* symbol = new_symbol(ch, storage, qualifier, specifier, *stars, 0, length);
    if (symbol == 0)
    {
        printf("symbol conflict!\n");
        exit(0);
    }
    code_gen_symbol(c, symbol);
    return symbol;
}

int len_gen_type_name(struct TypeName* node)
{
    struct SpecifierQualifierList* ptr = node->specifierQualifierList;
    while ((ptr->type & 0x01) == 0)
    {
        if (ptr->type < 2 && ptr->typeSpecifier < 8)
        {
            return len_gen_type_specifier(ptr->typeSpecifier);
        }
        ptr = ptr->specifierQualifierList;
    }
    return 0;
}

