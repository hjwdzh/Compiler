#include "util.h"

void labeled_statement(struct LabeledStatement* node); // tested
struct Symbol* expression_statement(struct ExpressionStatement* node);
void selection_statement(struct SelectionStatement* node);
void iteration_statement(struct IterationStatement* node);
void statement_func(struct Statement* node);
void statement_list(struct StatementList* node);
void compound_statement(struct CompoundStatement* node);
void function_definition(struct FunctionDefinition* node);
void external_declaration(struct ExternalDeclaration* node);
void translation_unit_begin(struct TranslationUnit* node);
void translation_unit(struct TranslationUnit* node);