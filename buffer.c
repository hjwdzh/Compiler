#include "util.h"

#define BUFFER_SIZE 100000
#define FUNCTION_SIZE 1000000
#include "buffer.h"

static char global_buffer[BUFFER_SIZE];
static char* ptr_stack[20];
static int ptr_top;

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
    freopen("/Users/skyer/Desktop/compiler/test.ll", "w", stdout);
    code_gen_with_header("test.c");
    printf("%s", global_buffer);
    fclose(stdout);
}

