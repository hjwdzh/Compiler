#include "symbol.h"
#include "util.h"
#include "buffer.h"
#define PRIME 99997
#define CREATE_NODE(a) ( (a*)malloc(sizeof(a)) )

static int symbols_prefix[150000] = {0};
static char* symbols_table[150000] = {0};

static struct DomainList* path[100];
static struct Symbol* symbol_arg[50];
static int Arg_ptr = 0;
static int Domain_ptr = 0;
static struct DomainList* cur = 0;
static struct StringTable* literals = 0;

void initialize_symbols() {
    symbols_prefix[0] = 0;
    symbols_table[0] = 0;

    cur = CREATE_NODE(struct DomainList);
    memset(cur, 0, sizeof(struct DomainList));
    cur->domain = CREATE_NODE(struct Domain);
    memset(cur->domain, 0, sizeof(struct Domain));
    path[Domain_ptr] = cur;
}

void release_domain_list(struct DomainList* list)
{
    struct SymbolList* l = list->domain->symbols;
    while (l)
    {
        struct SymbolList* p = l;
        l = l->next;
        int key = get_symbol(p->symbol->name);
        symbols_prefix[key]--;
        if (symbols_prefix[key] == 0)
        {
            free(symbols_table[key]);
            symbols_table[key] = 0;
        }
        free(p->symbol->name);
        free(p->symbol);
        free(p);
    }
    l = list->domain->discard;
    while (l)
    {
        struct SymbolList* p = l;
        l = l->next;
        int key = get_symbol(p->symbol->name);
        symbols_prefix[key]--;
        if (symbols_prefix[key] == 0)
        {
            free(symbols_table[key]);
            symbols_table[key] = 0;
        }
        free(p->symbol->name);
        free(p->symbol);
        free(p);
    }
    free(list->domain);
    free(list);
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
        code_gen_type_specifier(symbol_arg[i]->specifier, 0, symbol_arg[i]->length, symbol_arg[i]->stars);
        ADDSTRING(" ");
        code_gen_symbol('%', symbol_arg[i]);
        if (i != Arg_ptr - 1)
            ADDSTRING(", ");
    }
    Arg_ptr = 0;
}

void pop_para()
{
    int i = 0;
    for (i = 0; i < Arg_ptr; ++i)
    {
        symbol_arg[i]->prefix++;
        ADDSTRING("  ");
        code_gen_symbol('%', symbol_arg[i]);
        ADDSTRING(" = alloca ");
        code_gen_type_specifier(symbol_arg[i]->specifier, 0, symbol_arg[i]->length, symbol_arg[i]->stars);
        ADDSTRING(", align ");
        int len = len_gen_type_specifier(symbol_arg[i]->specifier);
        if (symbol_arg[i]->stars)
        {
            PTR_LENGTH == 8 ? (ADDSTRING("8\n")):(ADDSTRING("4\n"));
        }
        else
        {
            sprintf(buf, "%d\n", len);
            ADDSTRING(buf);
        }
        symbol_arg[i]->prefix--;
        ADDSTRING("  store ");
        code_gen_type_specifier(symbol_arg[i]->specifier, 0, symbol_arg[i]->length, symbol_arg[i]->stars);
        ADDSTRING(" ");
        code_gen_symbol('%', symbol_arg[i]);
        ADDSTRING(", ");
        code_gen_type_specifier(symbol_arg[i]->specifier, 0, symbol_arg[i]->length, symbol_arg[i]->stars);
        ADDSTRING("* ");
        symbol_arg[i]->prefix++;
        int key = get_symbol(symbol_arg[i]->name);
        symbols_prefix[key]++;
        code_gen_symbol('%', symbol_arg[i]);
        ADDSTRING("\n");
    }
    Arg_ptr = 0;
}

void back_domain()
{
    cur = path[Domain_ptr - 1];
}

void forward_domain()
{
    cur = path[Domain_ptr];
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
        release_domain_list(cur);
    else
    {
        struct SymbolList* symbol = cur->domain->symbols;
        if (symbol)
        {
            while (symbol->next)
            {
                symbol = symbol->next;
            }
            symbol->next = path[Domain_ptr]->domain->discard;
            path[Domain_ptr]->domain->discard = cur->domain->symbols;
        }
        symbol = cur->domain->discard;
        if (symbol)
        {
            while (symbol->next)
            {
                symbol = symbol->next;
            }
            symbol->next = path[Domain_ptr]->domain->discard;
            path[Domain_ptr]->domain->discard = cur->domain->discard;
        }
    }
    cur = path[Domain_ptr];
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
    symbols_table[key] = malloc(strlen(name)+1);
    strcpy(symbols_table[key], name);
    return key;
}

struct SymbolList* find_symbol(struct SymbolList* list, const char* name, int type)
{
    while (list)
    {
        if (strcmp(list->symbol->name, name) == 0)
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
    if (name && strlen(name))
        symbol->reference = symbol;
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
    symbol1->reference = symbol;
    return symbol1;
}

void new_global_buffer(struct Symbol* symbol, char* code, int isdefined)
{
    symbol->globalBuffer = CREATE_NODE(struct GlobalBuffer);
    memset(symbol->globalBuffer, 0, sizeof(struct GlobalBuffer));
    symbol->globalBuffer->isdefined = isdefined;
    symbol->globalBuffer->buffer = malloc(strlen(code)+1);
    strcpy(symbol->globalBuffer->buffer, code);
}

void code_gen_global_symbol()
{
    struct SymbolList* l = cur->domain->symbols;
    while (l)
    {
        if (l->symbol->type == 0)
        {
            printf("%s", l->symbol->globalBuffer->buffer);
        }
        l = l->next;
    }
}

struct Symbol* new_string(char* string)
{
    int i = 0;
    struct StringTable* l = literals;
    if (!l)
    {
        l = CREATE_NODE(struct StringTable);
        l->string = string;
        l->prefix = 1;
        literals = l;
    }
    else
    {
        while (l)
        {
            int t = strcmp(l->string, string);
            if (t == 0)
                break;
            if (l->next)
                l = l->next;
            else
            {
                l->next = CREATE_NODE(struct StringTable);
                l->next->string = string;
                l->next->prefix = l->prefix + 1;
                l = l->next;
                break;
            }
        }
    }
    long len = strlen(l->string);
    long len1 = len;
    for (i = 0; i < len1 - 1; ++i)
    {
        if (l->string[i] == '\\' && l->string[i + 1] == '0')
            len -= 2;
    }
    sprintf(buf, "getelementptr inbounds ([%lu x i8]* @.str%d, i32 0, i32 0)", len + 1, l->prefix - 1);
    return new_symbol(buf, 0, 1, 4, 1, 2, 0);
}

void code_gen_string()
{
    struct StringTable* l = literals;
    int i = 0;
    while (l)
    {
        long len = strlen(l->string);
        long len1 = len;
        for (i = 0; i < len1 - 1; ++i)
        {
            if (l->string[i] == '\\' && l->string[i + 1] == '0')
                len -= 2;
        }
        printf("@.str%d = private unnamed_addr constant [%lu x i8] c\"%s\\00\", align 1\n", l->prefix - 1, 1 + len, l->string);
        l = l->next;
    }
}