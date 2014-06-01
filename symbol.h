#ifndef _SYMBOL_JINGWEI_H_
#define _SYMBOL_JINGWEI_H_

struct GlobalBuffer {
    char* buffer;
    int isdefined;
};

struct SymbolList;

struct Symbol {
    int qualifier, specifier, type, stars, storage, length, depth;
    char* name;
    struct SymbolList* parameterlist;
    struct Symbol* reference;
    struct GlobalBuffer* globalBuffer;
    int prefix;
};

struct SymbolList {
    struct Symbol* symbol;
    struct SymbolList* next;
};
struct DomainList;

struct Domain {
    struct SymbolList* symbols;
    struct SymbolList* discard;
};

struct DomainList {
    struct Domain* domain;
    struct DomainList* next;
};

struct StringTable {
    char* string;
    int prefix;
    struct StringTable* next;
};

void back_domain();
void forward_domain();
void push_arg(struct Symbol* symbol);
void pop_arg();
void push_arg_buf(struct Symbol* symbol);
void cast_arg();
void reverse_arg_buf();
void pop_para(struct Symbol* symbol);
void reverse_arg();
void push_domain();
void pop_domain(int reset);
void initialize_symbols();
int get_symbol(char* name);
struct SymbolList* find_symbol(struct SymbolList* list, const char* name, int type);
struct Symbol* name2symbol(const char* name, int type);
struct Symbol* new_symbol(char* name, int storage, int qualifier, int specifier, int stars, int type, int length);
struct Symbol* load_symbol(struct Symbol* symbol);
void new_global_buffer(struct Symbol* symbol, char* code, int isdefined);
struct Symbol* new_string(char* string);

extern struct Symbol *g_symbol_printf, *g_symbol_scanf, *g_symbol_malloc;

extern int symbols_prefix[150000];

#endif