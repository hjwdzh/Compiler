#include "specify.h"
#include "buffer.h"
#include "calculation.h"

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
    char lbuf[20];
    if (!symbol)
    {
        printf("Symbol undefined!\n");
        exit(1);
    }
    int orig = parse_type(symbol->specifier);
    int cur = parse_type(specifier);
    if (orig == cur && symbol->stars == stars)
        return symbol;
    struct Symbol* newsymbol = 0;
    if (symbol->type == 2)
    {
        if (stars)
        {
            if (symbol->specifier & (3 << 6))
            {
                printf("Cannot cast float to double!\n");
                exit(1);
            }
            if (strcmp(symbol->name,"0") == 0)
            {
                free(symbol->name);
                symbol->name = malloc(5);
                strcpy(symbol->name, "null");
            }
            else
            {
            push_buffer(lbuf);
            ADDSTRING("inttoptr (");
            if (PTR_LENGTH == 8)
            {
                ADDSTRING("i64 ");
            }
            else
            {
                ADDSTRING("i32 ");
            }
                ADDSTRING(symbol->name);
                ADDSTRING(" to ");
                code_gen_type_specifier(specifier, 0, 0, stars);
                ADDSTRING(")");
                pop_buffer();
                free(symbol->name);
                long len = strlen(lbuf);
                symbol->name = (char*)malloc(len+1);
                strcpy(symbol->name, lbuf);
            }
        }
        symbol->specifier = specifier;
        symbol->stars = stars;
        return symbol;
    }
    if (symbol->stars == 0 && stars)
    {
        if (PTR_LENGTH == 8)
            symbol = cast_symbol(symbol, 32, 0);
        else
            symbol = cast_symbol(symbol, 16, 0);
    }
    ADDSTRING("  ");
    newsymbol = new_symbol("", 0, 0, specifier, symbol->stars, 0, symbol->length);
    code_gen_symbol('%', newsymbol);
    ADDSTRING(" = ");
    if (symbol->stars && stars)
    {
        ADDSTRING("bitcast");
    } else if (symbol->stars && !stars)
    {
        if (cur > 5)
        {
            printf("Cannot cast pointer to float!\n");
            exit(1);
        }
        ADDSTRING("ptrtoint");
    } else if (!symbol->stars && stars)
    {
        if (orig > 5)
        {
            printf("Cannot cast float to pointer!\n");
            exit(1);
        }
        ADDSTRING("inttoptr");
    } else
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
                    ADDSTRING("zext");
                }
                else
                {
                    ADDSTRING("sext");
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
    code_gen_type_specifier(specifier, 0, symbol->length, stars);
    ADDSTRING("\n");
    newsymbol->specifier = specifier;
    newsymbol->stars = stars;
    return newsymbol;
}

double foperate(double d1, double d2, char type)
{
    switch (type) {
        case '*':
            return d1 * d2;
            
        case '/':
            return d1 / d2;
            
        case '+':
            return d1 + d2;
            
        case '-':
            return d1 - d2;
            
        case '<':
            return d1 < d2;
            
        case '>':
            return d1 > d2;
        
        case '=':
            return d1 == d2;
            
        case '!':
            return d1 != d2;
            
        case 'o':
            return d1 || d2;
            
        case 'a':
            return d1 && d2;
            
        default:
            break;
    }
    return 0;
}

int doperate(int d1, int d2, char type)
{
    switch (type) {
        case '*':
            return d1 * d2;
            
        case '/':
            return d1 / d2;
            
        case '%':
            return d1 % d2;
            
        case '+':
            return d1 + d2;
            
        case '-':
            return d1 - d2;
            
        case 'l':
            return d1 << d2;
        
        case 'r':
            return d1 >> d2;
            
        case '<':
            return d1 < d2;
            
        case '>':
            return d1 > d2;
        
        case '&':
            return d1 & d2;
            
        case '^':
            return d1 ^ d2;
            
        case '|':
            return d1 | d2;
            
        case '=':
            return d1 == d2;
            
        case '!':
            return d1 != d2;
            
        case 'o':
            return d1 || d2;
            
        case 'a':
            return d1 && d2;
            
        default:
            break;
    }
    return 0;
}

int dsoperate(int f, char type)
{
    switch (type) {
        case 'n':
            return -f;
            
        case '-':
            return f - 1;
            
        case '~':
            return ~f;
            
        case '+':
            return f + 1;
            
        case '!':
            return !f;
            
        default:
            break;
    }
    return 0;
}

double fsoperate(double f, char type)
{
    switch (type) {
        case 'n':
            return -f;
            
        case '-':
            return f - 1;
            
        case '+':
            return f + 1;
            
        case '!':
            return !f;
        
        default:
            break;
    }
    return 0;
}

void operate_on_constant(struct Symbol* symbol1, struct Symbol* symbol2, char type)
{
    int d1, d2;
    double f1, f2;
    int s1 = parse_type(symbol1->specifier);
    int s2 = parse_type(symbol2->specifier);
    if (s1 == 5 || s1 == 6)
        sscanf(symbol1->name, "%lf", &f1);
    else
        sscanf(symbol1->name, "%d", &d1);
    if (s2 == 5 || s2 == 6)
        sscanf(symbol2->name, "%lf", &f2);
    else
        sscanf(symbol2->name, "%d", &d2);
    if (s1 == 5 || s1 == 6)
    {
        if (s2 == 5 || s2 == 6)
            f1 = foperate(f1, f2, type);
        else
            f1 = foperate(f1, d2, type);
        sprintf(symbol1->name, "%lf", f1);
    }
    else
    {
        if (s2 == 5 || s2 == 6)
            sprintf(symbol1->name, "%lf", foperate(d1, f2, type));
        else
            sprintf(symbol1->name, "%d", doperate(d1, d2, type));
    }
}

struct Symbol* convert_to_logic(struct Symbol* symbol)
{
    if (!symbol)
    {
        printf("Conditional expression fail!\n");
        exit(1);
    }
    if (symbol->stars)
    {
        symbol = cast_symbol(symbol, 32, 0);
    }
    if (symbol->specifier & 0x01)
        return symbol;
    struct Symbol* newsymbol = new_symbol("0", 0, 2, symbol->specifier, 0, 2, 0);
    return equality_symbol(symbol, newsymbol, 2, 1);
}