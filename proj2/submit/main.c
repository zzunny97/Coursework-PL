#include <stdio.h>


extern FILE *yyin;
main(argc, argv)
int argc;
char **argv;
{
    ++argv, --argc;	
    if(argc>0) {
        yyin = fopen(argv[0], "r");
    }
    else {
        yyerror("Usage: <cal.exe> <input file>");
        return -1;
    }

	yyparse();
}
