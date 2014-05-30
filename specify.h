#ifndef _SPECIFY_JINGWEI_H_
#define _SPECIFY_JINGWEI_H_

#include "util.h"

const char* declaration_specifiers(struct DeclarationSpecifiers* node, int* storage, int* qualifier, int* specifier, int isNotOutput);

void type_qualifier_list(struct TypeQualifierList* node, int *qualifier);
struct Symbol* cast_symbol(struct Symbol* symbol, int specifier, int stars);

int dsoperate(int f, char type);
double fsoperate(double f, char type);
void operate_on_constant(struct Symbol* symbol1, struct Symbol* symbol2, char type);
int parse_type(int specifier);
#endif