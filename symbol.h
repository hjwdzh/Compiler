#ifndef _SYMBOL_JINGWEI_H_
#define _SYMBOL_JINGWEI_H_

struct Symbol {
    int qualifier, specifier, type, stars, storage, length, depth;
    char* name;
    struct Symbol* reference;
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

void back_domain();
void forward_domain();
void push_arg(struct Symbol* symbol);
void pop_arg();
void pop_para();
void push_domain();
void pop_domain(int reset);
void initialize_symbols();
int get_symbol(char* name);
struct SymbolList* find_symbol(struct SymbolList* list, const char* name, int type);
struct Symbol* name2symbol(const char* name, int type);
struct Symbol* new_symbol(char* name, int storage, int qualifier, int specifier, int stars, int type, int length);
struct Symbol* load_symbol(struct Symbol* symbol);

#endif