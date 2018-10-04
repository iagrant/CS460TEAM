CC	= g++
LEX	= flex++
YACC	= bison
LIBS	= -L/usr/local/lib -lfl 

OBJS	= lex.yy.o C_grammar.tab.o
TESTOBJS	= driver.o lex.yy.o

C_grammmar: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

testscan: $(TESTOBJS) C_grammar.tab.h
	$(CC) -o $@ $(TESTOBJS) $(LIBS)

C_grammar.tab.cc: C_grammar.y
	$(YACC) -d -t $<

lex.yy.cc: scanner.lex C_grammar.tab.cc
	$(LEX) $<

clean:
	-rm -f lex.yy.* C_grammar.tab.* *.o C_grammar testscan *~

.SUFFIXES: .cc .o

.cc.o: $(CC) -c $< -o $@
