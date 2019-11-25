all:
	echo YACC
	bison -d ginko.y
	echo LEX
	flex ginko.l
	echo GCC
	gcc -o proj3 ginko.tab.c lex.yy.c main.c -lfl

clean:
	rm -f lex.yy.c ginko.tab.c ginko.tab.h proj3
