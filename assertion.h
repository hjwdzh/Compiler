#ifndef _ASSERTION_JINGWEI_H_
#define _ASSERTION_JINGWEI_H_

void test_changeable(struct Symbol* symbol);

void test_referenceable(struct Symbol* symbol);

void test_regular(struct Symbol* symbol);

void test_regular2(struct Symbol* symbol1, struct Symbol* symbol2);

void test_integer(struct Symbol* symbol);

void test_integer2(struct Symbol* symbol1, struct Symbol* symbol2);

void test_functionable(struct Symbol* symbol);

void test_functionable(struct Symbol* symbol);

void test_pointable(struct Symbol* symbol);

struct Symbol* test_calculable(struct Symbol* symbol, char type);

struct Symbol* test_calculable2(struct Symbol** symbol1, struct Symbol** symbol2, char type);

struct Symbol* test_add(struct Symbol** symbol1, struct Symbol** symbol2, int type);

void test_relation(struct Symbol** symbol1, struct Symbol** symbol2);

#endif