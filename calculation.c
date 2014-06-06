#include "calculation.h"
#include "specify.h"
#include "assertion.h"

struct Symbol* multiplicative_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type)
{
    test_regular2(symbol1, symbol2);
    char ch = '*';
    if (type == 2)
        ch = '/';
    if (type == 3)
        ch = '%';
    struct Symbol* symbol3 = test_calculable2(&symbol1, &symbol2, ch);
    if (symbol3)
        return symbol3;
    symbol3 = new_symbol("", symbol2->storage, 2, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    if ((symbol1->specifier & (3 << 6)) != 0)
    {
        ADDSTRING(" = f");
    }
    else
    {
        if (type == 3)
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
    if (type == 1)
    {
        ADDSTRING("mul ");
    }
    else if (type == 2)
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

struct Symbol* additive_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type)
{
    struct Symbol* symbol3 = test_add(&symbol1, &symbol2, type);
    if (symbol3)
        return symbol3;
    if (type == 1)
        symbol3 = test_calculable2(&symbol1, &symbol2, '+');
    else
        symbol3 = test_calculable2(&symbol1, &symbol2, '-');
    if (symbol3)
        return symbol3;
    symbol3 = test_calculable2(&symbol1, &symbol2, '+');
    if (symbol3)
        return symbol3;
    symbol3 = new_symbol("", symbol2->storage, 2, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    int isInteger = 1;
    if ((symbol3->specifier & (3 << 6)) != 0)
    {
        isInteger = 0;
        ADDSTRING(" = f");
    }
    else
    {
        ADDSTRING(" = ");
    }
    if (type == 2)
    {
        ADDSTRING("sub ");
    }
    else
    {
        ADDSTRING("add ");
    }
    code_gen_type_specifier(symbol3->specifier,isInteger,symbol3->length, symbol3->storage);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol('%', symbol2);
    ADDSTRING("\n");
    return symbol3;
}

struct Symbol* shift_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type)
{
    test_integer2(symbol1, symbol2);
    struct Symbol* symbol3;
    if (type == 1)
        symbol3 = test_calculable2(&symbol1, &symbol2, 'l');
    else
        symbol3 = test_calculable2(&symbol1, &symbol2, 'r');
    if (symbol3)
        return symbol3;
    symbol3 = new_symbol("", symbol2->storage, 2, symbol2->specifier, symbol2->stars, 0, symbol2->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    if ((symbol1->specifier & (1 << 9)) > 0)
    {
        ADDSTRING(" = lsh");
    }
    else
    {
        ADDSTRING(" = ash");
    }
    if (type == 1)
    {
        ADDSTRING("l ");
    }
    else
    {
        ADDSTRING("r ");
    }
    code_gen_type_specifier(symbol3->specifier,0,symbol3->length,symbol3->stars);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol('%', symbol2);
    ADDSTRING("\n");
    return symbol3;
}

struct Symbol* equality_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type, int isU)
{
    test_relation(&symbol1, &symbol2);
    struct Symbol* symbol3;
    if (type == 1)
        symbol3 = test_calculable2(&symbol1, &symbol2, '=');
    else
        symbol3 = test_calculable2(&symbol1, &symbol2, '!');
    if (symbol3)
        return symbol3;
    symbol3 = new_symbol("", 0, 2, 1, 0, 0, 0);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol3);
    if ((symbol2->specifier & (3 << 6)) != 0)
    {
        if (type == 1)
        {
            if (isU)
            {
                ADDSTRING(" = fcmp ueq ");
            }
            else
            {
                ADDSTRING(" = fcmp oeq ");
            }
        }
        else
        {
            if (isU)
            {
                ADDSTRING(" = fcmp une ");
            }
            else
            {
                ADDSTRING(" = fcmp one ");
            }
        }
    }
    else {
        if (type == 1)
        {
            ADDSTRING(" = icmp eq ");
        }
        else
        {
            ADDSTRING(" = icmp ne ");
        }
    }
    code_gen_type_specifier(symbol1->specifier,0, symbol1->length, symbol1->stars);
    ADDSTRING(" ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(", ");
    code_gen_symbol('%', symbol2);
    ADDSTRING("\n");
    return symbol3;
}

struct Symbol* and_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type)
{
    test_integer2(symbol1, symbol2);
    struct Symbol* symbol3 = test_calculable2(&symbol1, &symbol2, '&');
    if (symbol3)
        return symbol3;
    symbol3 = new_symbol("", symbol2->storage, 2, symbol2->specifier, symbol2->stars, 0, symbol2->length);
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

struct Symbol* exclusive_or_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type)
{
    test_integer2(symbol1, symbol2);
    struct Symbol* symbol3 = test_calculable2(&symbol1, &symbol2, '^');
    if (symbol3)
        return symbol3;
    symbol3 = new_symbol("", symbol2->storage, 2, symbol2->specifier, symbol2->stars, 0, symbol2->length);
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

struct Symbol* inclusive_or_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type)
{
    test_integer2(symbol1, symbol2);
    struct Symbol* symbol3 = test_calculable2(&symbol1, &symbol2, '|');
    if (symbol3)
        return symbol3;
    symbol3 = new_symbol("", symbol2->storage, 2, symbol2->specifier, symbol2->stars, 0, symbol2->length);
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

