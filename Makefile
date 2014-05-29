compiler:	   
	   lex c.l
	   yacc -dv c.y
	   cc declaration.c expression.c lex.yy.c specify.c statement.c symbol.c util.c buffer.c y.tab.c -o compiler

declaration: specify.o expression.o

expression:

lex.yy: 

specify: 

statement: buffer.o specify.o declaration.o

symbol: util.o

util: declaration.o

buffer: util.o

y.tab:

clean:
	rm compiler y.output
