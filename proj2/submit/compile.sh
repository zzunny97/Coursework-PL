echo LEX
flex cal.l
echo YACC
bison -d cal.y
echo GCC
#gcc -o cal.exe cal.tab.c lex.yy.c main.c -ly
gcc -o cal.exe cal.tab.c lex.yy.c main.c -ll
