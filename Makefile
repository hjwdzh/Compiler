compiler : declaration.o expression.o buffer.o lex.yy.o specify.o statement.o symbol.o util.o y.tab.o
	   cc *.o -o compiler

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
	rm *.o compiler
