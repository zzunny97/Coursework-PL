#include <stdio.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "db_type", "db_name", "db_port"}; 

int main() {
	int ntoken, vtoken;
	ntoken = yylex();
	//(continued in the next slide)
	while(ntoken) {
		printf("token type = %d\n", ntoken);
		if(yylex() != COLON) {
			printf("syntax error in line %d, Expected a ':' but found as %s\n", yylineno, yytext);
			return 1; 
		}
		vtoken = yylex();
		switch(ntoken) {
			case TYPE:
			case NAME:
				if(vtoken != IDENTIFIER) {
					printf("syntax error in line %d, Expected a ':' but found as %s\n", yylineno, yytext);
					return 1;
				}
				printf("%s is set to %s\n", names[ntoken], yytext);
				break;
		}
	}
	return 0;
}


