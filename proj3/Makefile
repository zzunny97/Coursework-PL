all:
	bison -d ginko.y
	flex ginko.l
#gcc -o proj3 ginko.tab.c lex.yy.c main.c -lfl
	gcc -c ginko.tab.c lex.yy.c
	gcc ginko.tab.o lex.yy.o main.c -o ginko

clean:
	rm -f lex.yy* ginko.tab* ginko.tab* ginko 
