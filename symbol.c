#include "symbol.h"
#include "util.h"
#define PRIME 99997
#define CREATE_NODE(a) ( (a*)malloc(sizeof(a)) )

static int symbols_prefix[150000] = {0};
static char* symbols_table[150000] = {0};

static struct DomainList* path[100];
static struct Symbol* symbol_arg[50];
static int Arg_ptr = 0;
static int Domain_ptr = 0;
static struct DomainList* cur = 0;

void initialize_symbols() {
    symbols_prefix[0] = 0;
    symbols_table[0] = 0;

    cur = CREATE_NODE(struct DomainList);
    memset(cur, 0, sizeof(struct DomainList));
    cur->domain = CREATE_NODE(struct Domain);
    memset(cur->domain, 0, sizeof(struct Domain));
    path[Domain_ptr] = cur;
}

void push_arg(struct Symbol* symbol)
{
    symbol_arg[Arg_ptr++] = symbol;
}

void pop_arg()
{
    int i = 0;
    for (i = 0; i < Arg_ptr; ++i)
    {
        code_gen_type_specifier(symbol_arg[i]->specifier, 0, 0, 0);
        ADDSTRING(" ");
        code_gen_symbol('%', symbol_arg[i]);
        if (i != Arg_ptr - 1)
            ADDSTRING(", ");
    }
    Arg_ptr = 0;
}

void push_domain()
{
    struct DomainList* node = CREATE_NODE(struct DomainList);
    memset(node, 0, sizeof(struct DomainList));
    node->domain = CREATE_NODE(struct Domain);
    memset(node->domain, 0, sizeof(struct Domain));
    cur->next = node;
    cur = cur->next;
    path[++Domain_ptr] = cur;
}

void pop_domain(int reset)
{
    path[Domain_ptr--] = 0;
    if (reset)
        symbols_prefix[0] = 1;
}

int get_symbol(char* name)
{
    unsigned long l = strlen(name);
    int key = 0;
    for (int i = 0; i < l; ++i)
        key = (key * 256 + name[i]) % PRIME;
    while (symbols_table[key] != 0)
    {
        if (strcmp(symbols_table[key], name) == 0)
            return key;
        ++key;
    }
    symbols_table[key] = name;
    return key;
}

struct SymbolList* find_symbol(struct SymbolList* list, const char* name, int type)
{
    while (list)
    {
        if (list->symbol->type == type && strcmp(list->symbol->name, name) == 0)
            return list;
        list = list->next;
    }
    return 0;
}

struct Symbol* name2symbol(const char* name, int type)
{
    int i;
    for (i = Domain_ptr; i >= 0; --i)
    {
        struct SymbolList* list = find_symbol(path[i]->domain->symbols, name, type);
        if (list)
            return list->symbol;
    }
    return 0;
}

struct Symbol* new_symbol(char* name, int storage, int qualifier, int specifier, int stars, int type, int length)
{
    struct Symbol* symbol = CREATE_NODE(struct Symbol);
    memset(symbol, 0, sizeof(struct Symbol));
    int key = 0;
    struct SymbolList* symbolList = 0;
    symbol->qualifier = qualifier;
    symbol->specifier = specifier;
    symbol->length = length;
    long len = strlen(name);
    symbol->name = (char*)malloc(len + 1);
    strcpy(symbol->name, name);
    symbol->storage = storage;
    symbol->stars = stars;
    symbol->type = type;
    symbol->depth = Domain_ptr;
    if (type == 2)
    {
        return symbol;
    }
    if (len > 0 && find_symbol(cur->domain->symbols, name, type))
    {
        printf("symbol %s redefined\n", name);
        exit(1);
    }
    key =get_symbol(name);
    symbol->prefix = symbols_prefix[key]++;
    symbol->prefix++;
    symbolList = CREATE_NODE(struct SymbolList);
    memset(symbolList, 0, sizeof(struct SymbolList));
    symbolList->symbol = symbol;
    symbolList->next = cur->domain->symbols;
    cur->domain->symbols = symbolList;
    return symbol;
}

struct Symbol* load_symbol(struct Symbol* symbol)
{
    struct Symbol *symbol1;
    if (!symbol->name || strlen(symbol->name) == 0 || symbol->type == 2)
        return symbol;
    symbol1 = new_symbol("", symbol->storage, 2, symbol->specifier, symbol->stars, 0, symbol->length);
    ADDSTRING("  ");
    code_gen_symbol('%', symbol1);
    ADDSTRING(" = load ");
    code_gen_type_specifier(symbol1->specifier, 0, symbol1->length, symbol1->stars);
    ADDSTRING("* ");
    code_gen_symbol('%', symbol);
    ADDSTRING(", align ");
    int l = len_gen_type_specifier(symbol1->specifier);
    sprintf(buf, "%d\n", l);
    ADDSTRING(buf);
    return symbol1;
}
