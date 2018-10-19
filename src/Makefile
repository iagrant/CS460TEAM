all: fcc

C_grammar.tab.c C_grammar.tab.h:	C_grammar.y
	bison -d -v -t C_grammar.y

lex.yy.c: scanner.lex C_grammar.tab.h
	flex scanner.lex C_grammar.tab.c

fcc: lex.yy.c C_grammar.tab.c C_grammar.tab.h
	g++ -std=c++11 -o $@ lex.yy.c

clean:
	-rm -f lex.yy.* C_grammar.tab.* *.o fcc
