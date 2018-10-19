all: fcc symbolDriver shadowTest RedefinitionTest pushPopTest

C_grammar.tab.c C_grammar.tab.h:	C_grammar.y
	bison -d -t C_grammar.y

lex.yy.c: scanner.lex C_grammar.tab.h
	flex scanner.lex C_grammar.tab.c

fcc: lex.yy.c C_grammar.tab.c C_grammar.tab.h
	g++ -std=c++11 -o $@ lex.yy.c

symbolDriver: symTableDriver.cpp
	g++ -std=c++11 symTableDriver.cpp -o $@

shadowTest: tests/symbolTableShadowing.cpp
	g++ -std=c++11 tests/symbolTableShadowing.cpp -o $@

RedefinitionTest: tests/symbolTableRedefinitionTest.cpp
	g++ -std=c++11 tests/symbolTableRedefinitionTest.cpp -o $@

pushPopTest: tests/symbolTablePushPop.cpp
	g++ -std=c++11 tests/symbolTablePushPop.cpp -o $@
clean:
	-rm -f lex.yy.* C_grammar.tab.* *.o fcc symbolDriver shadowTest RedefinitionTest pushPopTest