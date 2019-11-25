#include <stdio.h>

extern FILE *yyin;

int main(void) {
	yyparse();
	return 0;
}
/*
main(argc, argv)
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
