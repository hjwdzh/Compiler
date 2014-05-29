#ifndef _EXPRESSION_JINGWEI_H_
#define _EXPRESSION_JINGWEI_H_

#include "util.h"

struct Symbol* primary_expression(struct PrimaryExpression* node, struct Symbol** orig_symbol);
struct Symbol* postfix_expression(struct PostfixExpression* node, struct Symbol** orig_symbol);
struct Symbol* unary_expression(struct UnaryExpression* node, struct Symbol** orig_symbol);
struct Symbol* cast_expression(struct CastExpression* node);
struct Symbol* multiplicative_expression(struct MultiplicativeExpression* node);
struct Symbol* additive_expression(struct AdditiveExpression* node);
struct Symbol* shift_expression(struct ShiftExpression* node);
struct Symbol* relational_expression(struct RelationalExpression* node);
struct Symbol* equality_expression(struct EqualityExpression* node);
struct Symbol* and_expression(struct AndExpression* node);
struct Symbol* exclusive_or_expression(struct ExclusiveOrExpression* node);
struct Symbol* inclusive_or_expression(struct InclusiveOrExpression* node);
struct Symbol* logical_and_expression(struct LogicalAndExpression* node);
struct Symbol* logical_or_expression(struct LogicalOrExpression* node);
struct Symbol* conditional_expression(struct ConditionalExpression* node);
struct Symbol* assignment_expression(struct AssignmentExpression* node);
struct Symbol* expression_func(struct Expression* node);
void argument_expression_list(struct ArgumentExpressionList* node);

#endif