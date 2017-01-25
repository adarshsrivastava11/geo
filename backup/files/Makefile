.PHONY: all english hindi
CC = g++
CPPSOURCES = mapper.cpp interpreter.cpp action.cpp grammar.cpp filter.cpp parse.cpp lib.cpp
CPPOBJECTS = $(CPPSOURCES:.cpp=.o)
CPPHEADERS = $(CPPSOURCES:.cpp=.h)
EXECUTABLE = interpret.out

CSOURCES = context.c functions.c history.c lylib.c aux.c lex.yy.c y.tab.c
COBJECTS = $(CSOURCES:.c=.o)

#~ all: english hindi
all: interpret.out lyparser.out

english:
	cp ./english/english-source.vcb ./source.vcb
	cp ./english/english-target.vcb ./target.vcb
	cp ./english/alignment.txt ./

hindi:
	cp ./hindi/hindi-source.vcb ./source.vcb
	cp ./hindi/hindi-target.vcb ./target.vcb
	cp ./hindi/alignment.txt ./

interpret.out: main.cpp $(CPPOBJECTS) $(CPPHEADERS)
	$(CC) -g -o $@ $^

.cpp.o:
	$(CC) -g -c $< -o $@

.c.o:
	gcc -g -lm -c $< -o $@

lex.yy.c: tokenize.l
	flex tokenize.l

y.tab.c: lyparse.y
	yacc lyparse.y -Wall -k  --report=all -g -x -d -t		

lyparser.out: $(COBJECTS)
	gcc $^ -o $@ -pg -w -std=c++0x -lm

listkeywords:
	python listKeywords.py < target.vcb > keywords.txt

clean:
	rm -f drawing_instructions.txt
	rm -f *.out *.o
	rm -f lex.yy.c y.tab.c

install: y.tab.c lyparser.out interpret.out
	rm -f context.txt diff.txt history.txt
	echo -e "~POINTS\n~LINESEGMENTS\n~LINES\n~ARCS\n~ANGLE\n~CIRCLE" > diff.txt
	echo -e "~POINTS\n~LINESEGMENTS\n~LINES\n~ARCS\n~ANGLE\n~CIRCLE" > context.txt
	echo -e "~POINTS\n~LINESEGMENTS\n~LINES\n~ARCS\n~ANGLE\n~CIRCLE\n~PLOTTABLE END" > history.txt

