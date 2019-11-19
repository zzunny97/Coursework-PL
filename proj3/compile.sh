echo YACC
bison -d cal.y
echo LEX
flex cal.l
echo GCC
#gcc -o cal.exe cal.tab.c lex.yy.c main.c -ly
gcc -o proj2 cal.tab.c lex.yy.c main.c -lfl
