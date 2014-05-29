#ifndef _SPECIFY_JINGWEI_H_
#define _SPECIFY_JINGWEI_H_

#include "util.h"

const char* declaration_specifiers(struct DeclarationSpecifiers* node, int* storage, int* qualifier, int* specifier, int isNotOutput);

void type_qualifier_list(struct TypeQualifierList* node, int *qualifier);

#endif