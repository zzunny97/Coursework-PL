%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "tree.h"
#define MAX 100
typedef struct varr {
	double vall;
	char* name;
}varr;
varr reg[MAX];
int cur_idx;
int tmp;
%}

%union { 
	double dval; 
	int idx;
}


%token <dval> NUMBER
%token <idx> ID
%token IF ELSE THEN FUNC PRINT WHILE DO ENDIF
%type <dval> expr;

%%
program : func_decl stmt_list { }
        ;
stmt_list : stmt_list stmt {}
          | stmt {}
          ;

stmt : assign_stmt {}
     | print_stmt {}
     | if_stmt {}
     | while_stmt {}
     | func_call {}
     ;
assign_stmt : "SET" ID "to" expr ';' {}
            | "SET" ID "to" func_call ';' {}
            ;
print_stmt : "PRINT" expr ';' {
				printf("%lf\n", $2);
			 }
           ;
if_stmt : "IF" expr "THEN" stmt_list "ENDIF" {  }
        | "IF" expr "THEN" stmt_list "ELSE" stmt_list "ENDIF" {  }
        ;
while_stmt : "WHILE" expr "DO" stmt_list "ENDWHILE" {
			 }
           ;
func_decl : "FUNC" ID '(' param_list ')' '{' fstmt_list "RETURN" expr ';' '}' func_decl {}
          | "FUNC" ID '(' param_list ')' '{' fstmt_list "RETURN" func_call ';' '}' func_decl {}
          ;
fstmt_list : fstmt_list fstmt {}
           | fstmt {}
           ;
fstmt : assign_stmt {}
      | print_stmt  {}
      | if_stmt {}
      | while_stmt {}
      ;

param_list : ID ID_list {}
           ;
ID_list : ',' ID ID_list {}
        ;
func_call : ID '(' arg_list ')'  {}
          ;
arg_list : expr expr_list {}
         ;
expr_list : ',' expr expr_list {}
          ;
expr : '(' expr ')' { $$ = $2; }
     | '+' expr expr { $$ = $2 + $3; }
     | '-' expr expr { $$ = $2 - $3; }
     | '*' expr expr { $$ = $2 * $3; }
     | '/' expr expr { $$ = $2 / $3; }
     | '<' expr expr {
		if($2 < $3) $$ = 1;
		else $$ = 0;
	 }
     | '>' expr expr {
		if($2 > $3) $$ = 1;
		else $$ = 0;
	 } 
     | "<=" expr expr {
		if($2 <= $3) $$ = 1;
		else $$ = 0;
	 }
     | ">=" expr expr {
		if($2 >= $3) $$ = 1;
		else $$ = 0;
	 }
     | "==" expr expr {
		if($2 == $3) $$ = 1;
		else $$ = 0;
	 }
     | "!=" expr expr {
		if($2 != $3) $$ = 1;
		else $$ = 0;
	 }
     | '!' expr {$$ = -$2;}
     | NUMBER { $$ = $1; }
     | ID { tmp = $1; $$ = reg[$1].vall; }
     ;
%%

yyerror(char* s) {
//eval : expr EOL { if($1 == INT_MIN) { printf("Unknown variable: %s\n", reg[tmp].name); } else printf("=%lf\n", $1); }
//		 | ASS VAR expr EOL { reg[$2].vall = $3; } 
    extern char* yytext;
    extern int yylineno;
    fprintf(stdout, "%s\nLine No: %d\nAt char: %c\n", s, yylineno, *yytext);
}

int find_idx(char* var_name) {
	for(int i=0; i<cur_idx; i++) {
		if(strcmp(reg[i].name, var_name)==0) return i;		
	}
	reg[cur_idx].name = (char*)malloc(strlen(var_name)+1);
	reg[cur_idx].vall = INT_MIN;
	strcpy(reg[cur_idx].name, var_name);
	int ret = cur_idx;
	cur_idx++;
	return ret;
}

int yywrap() {
    return 0;
}

