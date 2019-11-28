#include <stdio.h>

extern FILE *yyin;
/*
int main(void) {
	yyparse();
	return 0;
}*/
/*main(argc, argv)
int argc;
char **argv;
{
    ++argv, --argc;	
    if(argc>0) {
        yyin = fopen(argv[0], "r");
    }
    else {
        yyerror("Usage: <proj2> <input file>");
        return -1;
    }

	yyparse();
}*/
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;
extern int yyparse(void);
int main(int argc, char* argv[]){
	if(argc != 2) {
		printf("no input!!\n");
		exit(EXIT_FAILURE);
	}
	int data;
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
	return 0;
}
