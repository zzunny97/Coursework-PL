all:
	bison -d ginko.y
	flex ginko.l
	gcc -w ginko.tab.c lex.yy.c main.c -o ginko -lfl

clean:
	rm -f lex.yy* ginko.tab* ginko.tab* ginko 
