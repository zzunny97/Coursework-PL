all:
	bison -d ginko.y
	flex ginko.l
	gcc ginko.tab.c lex.yy.c main.c -o ginko

clean:
	rm -f lex.yy* ginko.tab* ginko.tab* ginko 
