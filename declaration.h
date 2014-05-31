#ifndef _DECLARATION_JINGWEI_H_
#define _DECLARATION_JINGWEI_H_

#include "util.h"

extern int current_type;

void identifier_list(struct IdentifierList* node, char c);
char* direct_declarator(struct DirectDeclarator* node, char c, int *stars, int *length, int isOutput);
char* declarator_func(struct Declarator* declarator, int* qualifier, char c, int *stars, int* length, int isOutput);
void direct_abstract_declarator(struct DirectAbstractDeclarator* node);
void abstract_declarator(struct AbstractDeclarator* node);
void parameter_declaration(struct ParameterDeclaration* node, int *storage, int *qualifier, int *specifier);
void parameter_list(struct ParameterList* node);
void parameter_type_list(struct ParameterTypeList* node);
struct Symbol* declarator_def(struct Declarator* declarator, char c, int storage, int qualifier, int specifier, int* stars, int *length, int isdefined);
void initializer_func(struct Symbol* orig_symbol, struct Initializer* node, int specifier, char c, int stars);
void init_declarator(struct InitDeclarator* node, char c, int storage, int qualifier, int specifier);
void init_declarator_list(struct InitDeclaratorList* node, int storage, int qualifier, int specifier, char c);
void declaration_func(struct Declaration* declaration, char c);
void declaration_list(struct DeclarationList* node, char c);

#endif