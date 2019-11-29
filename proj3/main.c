#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
extern int yyparse(void);
int main(int argc, char* argv[]){
	if(argc != 2) {
		printf("Usage: ./ginko <input>\n");
		exit(EXIT_FAILURE);
	}
	int data;
	yyin = fopen(argv[1], "r");
	yyparse();
	fclose(yyin);
	return 0;
}
