compiler : declaration.o expression.o lex.yy.o specify.o statement.o symbol.o util.o y.tab.o

declaration: specify.o expression.o

expression:

lex.yy: 

specify: 

statement: specify.o declaration.o

symbol: util.o

util: declaration.o

y.tab:

clean:
	rm compiler *.o
