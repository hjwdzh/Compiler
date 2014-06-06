#include "util.h"

#define BUFFER_SIZE 100000
#define FUNCTION_SIZE 1000000
#include "buffer.h"

static char global_buffer[BUFFER_SIZE];
static char* ptr_stack[20];
static int ptr_top;
char name1[30], name2[30];

void initialize_buffer()
{
    g_ptr = global_buffer;
    ptr_top = 0;
    ptr_stack[ptr_top] = g_ptr;
}

void push_buffer(char* buf)
{
    ptr_stack[ptr_top] = g_ptr;
    g_ptr = buf;
    ptr_stack[++ptr_top] = buf;
}

void pop_buffer()
{
    g_ptr = ptr_stack[--ptr_top];
}

void code_gen()
{
    freopen(name2, "w", stdout);
    code_gen_with_header(name1);
    code_gen_string();
    code_gen_global_symbol();
    printf("%s", global_buffer);
    code_gen_standard_declaration();
    fclose(stdout);
}

