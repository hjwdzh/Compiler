#ifndef _UTIL_JINGWEI_H_
#define _UTIL_JINGWEI_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "symbol.h"

#define TARGET_TRIPLE "x86_64-apple-macosx10.8.0"
#define PTR_LENGTH 8
#define PTR_LEN_TYPE "i64"
#define ADDSTRING(a) {strcpy(g_ptr,a), g_ptr += strlen(a);}

extern char *g_ptr;
extern char buf[20];
extern int g_specifier, g_stars;

void code_gen_with_header(char *filename);
int len_gen_type_specifier(int val);
const char* code_gen_type_specifier(int val, int isnsw, int length, int stars);
int numPoint(struct Pointer* node);
void code_gen_symbol(char c, struct Symbol* symbol);
struct Symbol* gen_new_symbol(struct Declarator* declarator, char c, int storage, int qualifier, int specifier, int* stars, int *length, int isOutput, int isParameter);
int len_gen_type_name(struct TypeName* node);
void typename2specifier(struct TypeName* node, int *specifier, int *stars);
int abstract2stars(struct AbstractDeclarator* node);
int direct2stars(struct DirectAbstractDeclarator* node);

#endif