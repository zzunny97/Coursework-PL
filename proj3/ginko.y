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
int numfuncs;
double exec(Node* n);
Node* funcs[MAX];

%}

%union { 
	double dval; 
	int idx;
	struct Node* node_ptr;
}


%token <dval> NUMBER
%token <idx> ID
%token IF ELSE THEN FUNC PRINT WHILE DO ENDIF SET to ENDWHILE RETURN
%token GREQ_SYM LESQ_SYM EQ_SYM NEQ_SYM


%type <node_ptr> program func_decl stmt_list stmt assign_stmt print_stmt
%type <node_ptr> if_stmt while_stmt func_call fstmt_list fstmt param_list ID_list
%type <node_ptr> arg_list expr_list expr


%%
program : func_decl stmt_list {
			printf("===========program\n");
			printf("===========program\n");
			printf("===========program\n");
			printf("===========program\n");
			//exec($2);
		}
stmt_list : stmt_list stmt { 
				printf("stmt_list1\n");
				$$ = new_node(2, STMT_LIST, 2, $1, $2); 
			}
		  | stmt { 
			  printf("stmt_list2\n");
			  $$ = $1;
		  }
          ;

stmt : assign_stmt { 
		   printf("a-stmt\n");
		   $$ = $1;}
     | print_stmt { 
		 printf("p-stmt\n");
		 $$ = $1; }
     | if_stmt { $$ = $1;}
     | while_stmt {$$ = $1;}
     | func_call {$$ = $1;}
     ;
assign_stmt : SET ID to expr ';' { 
				 printf("assign_stmt: SET %s to %lf\n", vars[$2], $4);
				 Node* id_node = new_node_var(1, VAR, $2);
				 $$ = new_node(2, SET_EXPR, 2, id_node, $4); 
			  }
            | SET ID to func_call ';' {
				//printf("SET\n");
				Node* id_node = new_node_var(1, VAR, $2);
				$$ = new_node(2, SET_FUNC_CALL, 2, id_node, $4);
			}
            ;
print_stmt : PRINT expr ';' { 
				 printf("print_stmt\n");
				 //printf("yacc print\n"); 
				 $$ = new_node(2, PRINTSTMT, 1, $2); }
           ;
if_stmt : IF expr THEN stmt_list ENDIF { $$ = new_node(2, IFSTMT, 2, $2, $4); }
        | IF expr THEN stmt_list ELSE stmt_list ENDIF { $$ = new_node(2, IFSTMT, 3, $2, $4, $6);  }
        ;
while_stmt : WHILE expr DO stmt_list ENDWHILE { $$ = new_node(2, WHILE, 2, $2, $4); }
           ;
func_decl : FUNC ID '(' param_list ')' '{' fstmt_list RETURN expr ';' '}' func_decl {
				printf("func_decl\n");
				Node* func_name = new_node_func(2, FUNC_NAME, $2);
				pushFunc(func_name);
				$$ = new_node(2, FUNC_DECL, 5, func_name, $4, $7, $9, $12);
			}
          | FUNC ID '(' param_list ')' '{' fstmt_list RETURN func_call ';' '}' func_decl {
			  printf("func_decl\n");
			  Node* func_name = new_node_func(2, FUNC_NAME, $2);
			  pushFunc(func_name);
			  $$ = new_node(2, FUNC_DECL, 5, func_name, $4, $7, $9, $12);
		  }
		  | /*epsilon*/{
			  printf("epsilon\n");
		  }
          ;
fstmt_list : fstmt_list fstmt {
				$$ = new_node(2, FSTMT_LIST, 2, $1, $2);
			}
           | fstmt {
			   	$$ = new_node(2, FSTMT_LIST, 1, $1);
		   }
           ;
fstmt : assign_stmt { $$ = $1; }
      | print_stmt  { $$ = $1; }
      | if_stmt		{ $$ = $1; }
      | while_stmt	{ $$ = $1; }
      ;

param_list : ID ID_list {
				$$ = new_node(2, PARAM_LIST, 2, $1, $2);
			 }
           ;
ID_list : ',' ID ID_list {
				$$ = new_node(2, ID_LIST, 2, $2, $3);
			}
		| /* epsilon */ {}
        ;
func_call : ID '(' arg_list ')'  {
				$$ = new_node(2, FUNC_CALL, 2, $1, $3);
			}
          ;
arg_list : expr expr_list {
				$$ = new_node(2, ARG_LIST, 2, $1, $2);
		   }
         ;
expr_list : ',' expr expr_list { 
				$$ = new_node(2, EXPR_LIST, 2, $2, $3);
			}
		  | /* epsilon */ {}
          ;
expr : '(' expr ')'		{ $$ = new_node(2, PAR, 1, $2); }
	 | '+' expr expr	{ $$ = new_node(2, PLUS, 2, $2, $3); }
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
     | NUMBER			{ $$ = new_node_num(0, NUM, $1); }
     | ID				{ 
		 //printf("expr ID\n");
		 $$ = new_node_var(1, VAR, $1); }
     ;
%%

int yyerror(char* s) {
//eval : expr EOL { if($1 == INT_MIN) { printf("Unknown variable: %s\n", reg[tmp].name); } else printf("=%lf\n", $1); }
//		 | ASS VAR expr EOL { reg[$2].vall = $3; } 
    extern char* yytext;
    extern int yylineno;
    fprintf(stdout, "%s\nLine No: %d\nAt char: %s\n", s, yylineno, yytext);
}

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

void pushFunc(struct Node* n) {
	funcs[numfuncs++] = n;
}


double exec(Node* n) {
	printf("exec()\n");
	if(!n) {
		return 0;
	}
	switch(n->type){
		case 0: 
			return n->val;
		case 1: 
			return vals[n->var_idx];
		case 2:
			switch(n->op){
				case PROGRAM: return exec(n->next[1]);
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
					//return vals[n->next[0]->var_idx] = exec(n->next[1]);
					vals[n->next[0]->var_idx] = exec(n->next[1]);
					//printf("%lf\n", exec(n->next[1]));
					return vals[n->next[0]->var_idx];
				case PRINTSTMT:	
					printf("====== Real print: %lf\n", exec(n->next[0])); 
					return 0;
				case IFSTMT:
					if(exec(n->next[0])) return exec(n->next[1]);
					else if(n->op_cnt == 3) return exec(n->next[2]);
				//case FUNC_DECL:
					
				case FUNC_CALL:
					for(int i=0; i<numfuncs; i++) {
						if(n->next[0]->var_idx == funcs[i]->var_idx) {
							exec(funcs[i]);
							return exec(n->next[4]);
						}
					}
				case STMT:
					return exec(n->next[0]);
				//case STMT_LIST:
					

				//case FSTMT_LIST:
					
				//case PARAM_LIST:

				//case ID_LIST:

				//case ARG_LIST:

				//case EXPR_LIST:


				
			}
	}
	return 0;
}
