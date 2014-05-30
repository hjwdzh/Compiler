#ifndef _CALCULATION_JINGWEI_H_
#define _CALCULATION_JINGWEI_H_

struct Symbol* multiplicative_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type);
struct Symbol* additive_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type);
struct Symbol* shift_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type);
struct Symbol* equality_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type, int isU);
struct Symbol* and_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type);
struct Symbol* exclusive_or_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type);
struct Symbol* inclusive_or_symbol(struct Symbol* symbol1, struct Symbol* symbol2, int type);

#endif