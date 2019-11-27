%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ginkoNode.h"

#define MAX 100

char* vars[MAX];
double vals[MAX];
int numvars;
double symbols[MAX];
double exec(Node* n);

// int cur_idx;
// int tmp;
%}

%union { 
	double dval; 
	int idx;
	struct Node* node_ptr;
};


%token <dval> NUMBER
%token <idx> ID
%token IF ELSE THEN FUNC PRINT WHILE DO ENDIF SET to ENDWHILE RETURN
%token GREQ_SYM LESQ_SYM EQ_SYM NEQ_SYM


%type <node_ptr> program func_decl stmt_list stmt assign_stmt print_stmt
%type <node_ptr> if_stmt while_stmt func_call fstmt_list fstmt param_list ID_list
%type <node_ptr> arg_list expr_list expr

%%
program : func_decl stmt_list {}
        ;
stmt_list : stmt_list stmt { exec($2); }
          | stmt { exec($1); }
          ;

stmt : assign_stmt { $$ = $1;}
     | print_stmt { $$ = $1; }
     | if_stmt { $$ = $1;}
     | while_stmt {$$ = $1;}
     | func_call {$$ = $1;}
     ;
assign_stmt : SET ID to expr ';' { 
				  Node* id_node = new_node_var(1, VAR, $2);
				  $$ = new_node(2, SET_EXPR, 2, id_node, $4); 
			  }
            | SET ID to func_call ';' {}
            ;
print_stmt : PRINT expr ';' { 
				 //printf("yacc print\n"); 
				 $$ = new_node(2, PRINTSTMT, 1, $2); }
           ;
if_stmt : IF expr THEN stmt_list ENDIF { $$ = new_node(2, IFSTMT, 2, $2, $4); }
        | IF expr THEN stmt_list ELSE stmt_list ENDIF { $$ = new_node(2, IF, 3, $2, $4, $6);  }
        ;
while_stmt : WHILE expr DO stmt_list ENDWHILE { $$ = new_node(2, WHILE, 2, $2, $4); }
           ;
func_decl : FUNC ID '(' param_list ')' '{' fstmt_list RETURN expr ';' '}' func_decl {}
          | FUNC ID '(' param_list ')' '{' fstmt_list RETURN func_call ';' '}' func_decl {}
		  | /* epsilon */ {}
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
		| /* epsilon */ {}
        ;
func_call : ID '(' arg_list ')'  {}
          ;
arg_list : expr expr_list {}
         ;
expr_list : ',' expr expr_list {  }
		  | /* epsilon */ {}
          ;
expr : '(' expr ')'		{ $$ = new_node(2, PAR, 1, $2); }
	 | '+' expr expr	{ 
		 //printf("expr plus\n"); 
		 $$ = new_node(2, PLUS, 2, $2, $3); }
     | '-' expr expr	{ $$ = new_node(2, MINUS, 2, $2, $3); }
     | '*' expr expr	{ $$ = new_node(2, MUL, 2, $2, $3);  }
     | '/' expr expr	{ $$ = new_node(2, DIV, 2, $2, $3);}
     | '<' expr expr	{ $$ = new_node(2, LES, 2, $2, $3); }	
     | '>' expr expr	{ $$ = new_node(2, GRE, 2, $2, $3); }
     | LESQ_SYM expr expr	{ $$ = new_node(2, LESQ, 2, $2, $3); }
     | GREQ_SYM expr expr	{ $$ = new_node(2, GREQ, 2, $2, $3); }
     | EQ_SYM expr expr	{ $$ = new_node(2, EQ, 2, $2, $3); }
     | NEQ_SYM expr expr	{ $$ = new_node(2, NEQ, 2, $2, $3); }
     | '!' expr			{ $$ = new_node(2, NEG, 1, $2); }
     | NUMBER			{ 
		 //printf("YACC NUMBER\n"); 
		 $$ = new_node_num(0, NUM, $1); }
     | ID				{ $$ = new_node_var(1, VAR, $1); }
     ;
%%

int yyerror(char* s) {
//eval : expr EOL { if($1 == INT_MIN) { printf("Unknown variable: %s\n", reg[tmp].name); } else printf("=%lf\n", $1); }
//		 | ASS VAR expr EOL { reg[$2].vall = $3; } 
    extern char* yytext;
    extern int yylineno;
    fprintf(stdout, "%s\nLine No: %d\nAt char: %s\n", s, yylineno, yytext);
}

/*
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
}*/

int yywrap() {
    return 0;
}

int findindex(char* var) {
	for(int i=0; i<numvars; i++) {
		if(strcmp(var, vars[i])==0)
			return i;
	}
	vars[numvars] = strdup(var);
	return numvars++;
}

double exec(Node* n) {
	//printf("func: exec\n");
	if(!n) return 0;
	switch(n->type){
		case 0: return n->val;
		case 1: return vals[n->var_idx];
		case 2:
			switch(n->op){
				case PAR:	return exec(n->next[0]);
				case NEG:	return -exec(n->next[0]);
				case PLUS:	return exec(n->next[0]) + exec(n->next[1]);
				case MINUS:	return exec(n->next[0]) - exec(n->next[1]);
				case MUL:	return exec(n->next[0]) * exec(n->next[1]);
				case DIV:	return exec(n->next[0]) / exec(n->next[1]);
				case LES:	return exec(n->next[0]) < exec(n->next[1]);
				case GRE:	return exec(n->next[0]) > exec(n->next[1]);
				case LESQ:	return exec(n->next[0]) <= exec(n->next[1]);
				case GREQ:	return exec(n->next[0]) >= exec(n->next[1]);
				case EQ:	return exec(n->next[0]) == exec(n->next[1]);
				case NEQ:	return exec(n->next[0]) != exec(n->next[1]);
				case WHILE:
					while(exec(n->next[0]))
						exec(n->next[1]);
					return 0;
				case SET_EXPR:
					//return symbols[n->next[0]->var_idx] = exec(n->next[1]);
					return vals[n->next[0]->var_idx] = exec(n->next[1]);
					//symbols[n->next[0]->var_idx] = exec(n->next[1]);
					//return symbols[n->next[0]->var_idx];
					
				case PRINTSTMT:	printf("%lf\n", exec(n->next[0])); return 0;
				case IFSTMT:
					if(exec(n->next[0])) exec(n->next[1]);
					else if(n->op_cnt == 3) exec(n->next[2]);
			}
	}
	return 0;
}
