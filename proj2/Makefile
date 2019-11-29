all:
	echo YACC
	bison -d cal.y
	echo LEX
	flex cal.l
	echo GCC
	gcc -o proj2 cal.tab.c lex.yy.c main.c -lfl

clean:
	rm -f lex.yy.c cal.tab.c cal.tab.h proj2
