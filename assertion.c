#include "util.h"
#include "symbol.h"
#include "specify.h"
#include "calculation.h"

void test_changeable(struct Symbol* symbol)
{
    if (!symbol || symbol->qualifier & 0x02)
    {
        printf("Read-only variable is not assignable!\n");
        exit(1);
    }
}

void test_referenceable(struct Symbol* symbol)
{
    if (symbol->stars == 0)
    {
        printf("Indirection requires pointer operand!\n");
        exit(1);
    }
}

void test_regular(struct Symbol* symbol)
{
    if (symbol->stars)
    {
        printf("Invalid oprands: need plain type!\n");
        exit(1);
    }
}

void test_regular2(struct Symbol* symbol1, struct Symbol* symbol2)
{
    test_regular(symbol1);
    test_regular(symbol2);
}

void test_integer(struct Symbol* symbol)
{
    test_regular(symbol);
    if (symbol->specifier & (3 << 6))
    {
        printf("Invalid oprands: need integer type!\n");
        exit(1);
    }
}

void test_integer2(struct Symbol* symbol1, struct Symbol* symbol2)
{
    test_integer(symbol1);
    test_integer(symbol2);
}

void test_functionable(struct Symbol* symbol)
{
    if (!symbol || symbol->type != 1)
    {
        printf("Invalid call: symbol is not a function or function pointer!\n");
        exit(1);
    }
}

void test_pointable(struct Symbol* symbol)
{
    if (symbol->reference == 0)
    {
        printf("Invalid oprands: value cannot be pointed!\n");
        exit(1);
    }
}

struct Symbol* test_calculable2(struct Symbol** symbol1, struct Symbol** symbol2, char type)
{
    if ((*symbol1)->type != 2 || (*symbol2)->type != 2)
    {
        if (type == 'o' || type == 'a')
            return 0;
        int s1 = parse_type((*symbol1)->specifier);
        int s2 = parse_type((*symbol2)->specifier);
        if (s1 < s2)
            *symbol1 = cast_symbol(*symbol1, (*symbol2)->specifier, (*symbol2)->stars);
        else
            *symbol2 = cast_symbol(*symbol2, (*symbol1)->specifier, (*symbol1)->stars);
        return 0;
    }
    operate_on_constant(*symbol1, *symbol2, type);
    return *symbol1;
}

struct Symbol* test_calculable(struct Symbol* symbol, char type)
{
    if (symbol->type != 2)
        return 0;
    double f;
    int d;
    if (symbol->specifier & (3 << 6))
    {
        sscanf(symbol->name, "%lf", &f);
        sprintf(symbol->name, "%lf", fsoperate(f, type));
        return symbol;
    }
    else
    {
        sscanf(symbol->name, "%d", &d);
        sprintf(symbol->name, "%d", dsoperate(d, type));
        return symbol;
    }
}

struct Symbol* test_add(struct Symbol** symbol1, struct Symbol** symbol2, int type)
{
    if ((*symbol1)->stars && (*symbol2)->stars)
    {
        printf("Invalid oprands: pointer cannot be subtracted!\n");
        exit(1);
    }
    if (!(*symbol1)->stars && !(*symbol2)->stars)
    {
        return 0;
    }
    if (type == 2)
    {
        if ((*symbol2)->stars)
        {
            printf("Invalid oprands: pointer cannot be subtracted!\n");
            exit(1);
        }
    }
    if ((*symbol1)->stars)
    {
        struct Symbol* symbol3;
        if (type == 2)
        {
            symbol3 = new_symbol("0", 0, 2, 16, 0, 2, 0);
            *symbol2 = additive_symbol(symbol3, *symbol2, 2);
        }
        *symbol2 = cast_symbol(*symbol2, 32, 0);
        symbol3 = new_symbol("", 0, 2, (*symbol1)->specifier, (*symbol1)->stars, 0, (*symbol1)->length);
        ADDSTRING("  ");
        code_gen_symbol('%', symbol3);
        ADDSTRING(" = getelementptr inbounds ");
        code_gen_type_specifier((*symbol1)->specifier, 0, (*symbol1)->length, (*symbol1)->stars);
        ADDSTRING(" ");
        code_gen_symbol('%', *symbol1);
        ADDSTRING(" , i64 ");
        code_gen_symbol('%', *symbol2);
        ADDSTRING("\n");
        return symbol3;
    }
    else
    {
        *symbol1 = cast_symbol(*symbol1, 32, 0);
        struct Symbol* symbol3 = new_symbol("", 0, 2, (*symbol2)->specifier, (*symbol2)->stars, 0, (*symbol2)->length);
        ADDSTRING("  ");
        code_gen_symbol('%', symbol3);
        ADDSTRING(" = getelementptr inbounds ");
        code_gen_type_specifier((*symbol2)->specifier, 0, (*symbol2)->length, (*symbol2)->stars);
        ADDSTRING(" ");
        code_gen_symbol('%', *symbol2);
        ADDSTRING(", i64 ");
        code_gen_symbol('%', *symbol1);
        ADDSTRING("\n");
        return symbol3;
    }
    return 0;
}

void test_relation(struct Symbol** symbol1, struct Symbol** symbol2)
{
    if ((*symbol1)->stars && (*symbol2)->stars == 0 && ((*symbol2)->specifier & (3 << 6)))
    {
        printf("Invalid oprands: pointer cannot compare to double!\n");
        exit(1);
    }
    if ((*symbol2)->stars && (*symbol1)->stars == 0 && ((*symbol1)->specifier & (3 << 6)))
    {
        printf("Invalid oprands: pointer cannot compare to double!\n");
        exit(1);
    }
    if ((*symbol1)->stars < (*symbol2)->stars)
    {
        *symbol1 = cast_symbol(*symbol1, (*symbol2)->specifier, (*symbol2)->stars);
    }
    if ((*symbol1)->stars > (*symbol2)->stars)
    {
        *symbol2 = cast_symbol(*symbol2, (*symbol1)->specifier, (*symbol1)->stars);
    }
}

void test_constant(struct Symbol* symbol1)
{
    if (symbol1->type != 2)
    {
        printf("Cannot make declaration with a variable!\n");
        exit(1);
    }
}