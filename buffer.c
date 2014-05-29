#include "util.h"

#define BUFFER_SIZE 100000
#define FUNCTION_SIZE 1000000
#include "buffer.h"

static char global_buffer[BUFFER_SIZE];

void initialize_buffer()
{
    g_ptr = global_buffer;
}

void code_gen()
{
    printf("%s", global_buffer);
}

