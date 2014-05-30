compiler:	   
	   lex c.l
	   yacc -dv c.y
	   cc declaration.c assertion.c expression.c lex.yy.c specify.c statement.c symbol.c util.c buffer.c y.tab.c calculation.c -o compiler

declaration: specify.o expression.o

expression:

calculation: specify.o assertion.o

lex.yy: 

specify: 

statement: buffer.o specify.o declaration.o

symbol: util.o

util: declaration.o

buffer: util.o

y.tab:

assertion: util.o specify.o symbol.o

clean:
	rm compiler y.output lex.yy.c y.tab.c y.tab.h test.ll
