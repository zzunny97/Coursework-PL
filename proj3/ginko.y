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
Node* func_root;
double stack[MAX];
int head;
int tail;
int arg_cnt;
int par_cnt;
    
extern int yylineno;
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
			func_root = $1;
			exec($2);
		}
stmt_list : stmt_list stmt { 
				//printf("stmt_list1\n");
				$$ = new_node(2, STMT_LIST, 2, $1, $2); 
			}
		  | stmt { 
			  //printf("stmt_list2\n");
			  $$ = $1;
		  }
          ;

stmt : assign_stmt { 
		   //printf("a-stmt\n");
		   $$ = $1;}
     | print_stmt { 
		 //printf("p-stmt\n");
		 $$ = $1; }
     | if_stmt { $$ = $1;}
     | while_stmt {$$ = $1;}
     | func_call {$$ = $1;}
     ;
assign_stmt : SET ID to expr ';' { 
				 //printf("assign_stmt: SET %s to %lf\n", vars[$2], $4);
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
				 //printf("print_stmt\n");
				 //printf("yacc print\n"); 
				 $$ = new_node(2, PRINTSTMT, 1, $2); }
           ;
if_stmt : IF expr THEN stmt_list ENDIF { $$ = new_node(2, IFSTMT, 2, $2, $4); }
        | IF expr THEN stmt_list ELSE stmt_list ENDIF { $$ = new_node(2, IFSTMT, 3, $2, $4, $6);  }
        ;
while_stmt : WHILE expr DO stmt_list ENDWHILE { $$ = new_node(2, WHILE, 2, $2, $4); }
           ;
func_decl : FUNC ID '(' param_list ')' '{' fstmt_list RETURN expr ';' '}' func_decl {
				//printf("func_decl1\n");
				Node* func_name = new_node_func(2, FUNC_NAME, $2);
				//pushFunc(func_name);
				//$$ = new_node(2, FUNC_DECL, 5, func_name, $4, $7, $9, $12);
				Node* nn = new_node(2, FUNC_DECL, 5, func_name, $4, $7, $9, $12);
				pushFunc(nn);
				$$ = nn;
			}
          | FUNC ID '(' param_list ')' '{' fstmt_list RETURN func_call ';' '}' func_decl {
			  //printf("func_decl2\n");
			  Node* func_name = new_node_func(2, FUNC_NAME, $2);
			  //pushFunc(func_name);
			  //$$ = new_node(2, FUNC_DECL, 5, func_name, $4, $7, $9, $12);
			  Node* nn = new_node(2, FUNC_DECL, 5, func_name, $4, $7, $9, $12);
			  pushFunc(nn);
			  $$ = nn;
		  }
		  | /*epsilon*/{
		  }
          ;
fstmt_list : fstmt_list fstmt {
				$$ = new_node(2, FSTMT_LIST, 2, $1, $2);
			}
           | fstmt {
			   	//$$ = new_node(2, FSTMT_LIST, 1, $1);
			    $$ = $1;
		   }
           ;
fstmt : assign_stmt { $$ = $1; }
      | print_stmt  { $$ = $1; }
      | if_stmt		{ $$ = $1; }
      | while_stmt	{ $$ = $1; }
      ;

param_list : ID ID_list {
				Node* id_node = new_node_var(2,	FUNC_NAME_TMP, $1); 
				$$ = new_node(2, PARAM_LIST, 2, id_node, $2);
			 }
           ;
ID_list : ',' ID ID_list {
				Node* id_node = new_node_var(2,	FUNC_NAME_TMP, $2); 
				$$ = new_node(2, ID_LIST, 2, id_node, $3);
			}
		| /* epsilon */ { $$ = new_node(3, EPSILON, 0); }
        ;
func_call : ID '(' arg_list ')'  {
				Node* id_node = new_node_var(2,	FUNC_NAME_TMP, $1); 
				$$ = new_node(2, FUNC_CALL, 2, id_node, $3);
			}
          ;
arg_list : expr expr_list {
			    //Node* list_tmp = new_node(2, EXPR_LIST_TMP, 1, $2);
				//$$ = new_node(2, ARG_LIST, 2, $1, list_tmp);
				$$ = new_node(2, ARG_LIST, 2, $1, $2);
		   }
         ;
expr_list : ',' expr expr_list { 
				//Node* list_tmp = new_node(2, EXPR_LIST_TMP, 1, $3);
				//$$ = new_node(2, EXPR_LIST, 2, $2, list_tmp);
				$$ = new_node(2, EXPR_LIST, 2, $2, $3);
			}
		  | /* epsilon */ { $$ = new_node(3, EPSILON, 0); }
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

yyerror(char* s) {
    extern char* yytext;
    //extern int yylineno;
	printf("Error: %d\n", yylineno);
    //fprintf(stdout, "%s\nLine No: %d\nAt char: %s\n", s, yylineno, yytext);
}


int findindex(char* var) {
	if(numvars == 0) {
		for(int i=0; i<MAX; i++)
			vals[i] = INT_MIN;
	}
	for(int i=0; i<numvars; i++) {
		if(strcmp(var, vars[i])==0)
			return i;
	}
	//printf("new var: %s\n", var);
	vars[numvars] = strdup(var);
	return numvars++;
}

void pushFunc(struct Node* n) {
	//printf("pushFunc cur numfuncs: %d\n", numfuncs);
	funcs[numfuncs++] = n;
}


double exec(Node* n) {
	//printf("exec\n");
	if(!n) {
		printf("n is null return exec\n");
		return 0;
	}
	if(n == NULL)
		printf("n is null!!!\n");
	switch(n->type){
		case 0:
			return n->val;
		case 1: 
			//printf("%s\n", vars[n->var_idx]);
			//printf("%lf\n", vals[n->var_idx]);
			if(vals[n->var_idx] == INT_MIN) {
				printf("Unknown variable: %s\n", vars[n->var_idx]);
				exit(-1);
			}
			return vals[n->var_idx];
		case 2:
			switch(n->op){
				case PROGRAM: return exec(n->next[1]);
				case PAR:
					//stack[top++] = exec(n->next[0]);
					return exec(n->next[0]);
				case NEG:	
					//stack[top++] = exec(n->next[0]);
					return -exec(n->next[0]);
				case PLUS:	
					//stack[top++] = exec(n->next[0]) + exec(n->next[1]);
					return exec(n->next[0]) + exec(n->next[1]);
				case MINUS:	
					//stack[top++] = exec(n->next[0]) - exec(n->next[1]);
					return exec(n->next[0]) - exec(n->next[1]);
				case MUL:	
					//stack[top++] = exec(n->next[0]) * exec(n->next[1]);
					return exec(n->next[0]) * exec(n->next[1]);
				case DIV:	
					//stack[top++] = exec(n->next[0]) / exec(n->next[1]);
					return exec(n->next[0]) / exec(n->next[1]);
				case LES:	
					//stack[top++] = exec(n->next[0]) < exec(n->next[1]);
					return exec(n->next[0]) < exec(n->next[1]);
				case GRE:	
					//stack[top++] = exec(n->next[0]) > exec(n->next[1]);
					return exec(n->next[0]) > exec(n->next[1]);
				case LESQ:	
					//stack[top++] = exec(n->next[0]) <= exec(n->next[1]);
					return exec(n->next[0]) <= exec(n->next[1]);
				case GREQ:	
					//stack[top++] = exec(n->next[0]) >= exec(n->next[1]);
					return exec(n->next[0]) >= exec(n->next[1]);
				case EQ:	
					//stack[top++] = exec(n->next[0]) == exec(n->next[1]);
					return exec(n->next[0]) == exec(n->next[1]);
				case NEQ:	
					//stack[top++] = exec(n->next[0]) != exec(n->next[1]);
					return exec(n->next[0]) != exec(n->next[1]);
				case WHILE:
					while(exec(n->next[0]))
						exec(n->next[1]);
					return 0;
				case SET_EXPR:
					//printf("case SET_EXPR\n");
					return vals[n->next[0]->var_idx] = exec(n->next[1]);
				case SET_FUNC_CALL:
					//printf("case SET_FUNC_CALL\n");
					return vals[n->next[0]->var_idx] = exec(n->next[1]);
				case PRINTSTMT:	
					//printf("case PRINTSTMT\n");
					printf("%lf\n", exec(n->next[0])); 

					//printf("%lf\n", exec(n->next[0])); 
					return 0;
				case IFSTMT:
					//printf("case IFSTMT\n");
					if(exec(n->next[0])) return exec(n->next[1]);
					else if(n->op_cnt == 3) return exec(n->next[2]);
				case FUNC_CALL:
					//printf("case FUNC_CALL\n");
					exec(n->next[1]);	

					for(int i=0; i<numfuncs; i++) {
						if(n->next[0]->var_idx == funcs[i]->next[0]->var_idx) {
							//printf("executing function\n");
							return exec(funcs[i]);
						}
					}
				case ARG_LIST:
					//printf("case ARG_LIST how many args: %d\n", n->op_cnt);
					arg_cnt = 0;
					Node* ccur = n;
					while(ccur->next[1] != NULL) {
						arg_cnt++;
						ccur = ccur->next[1];
						if(ccur == NULL)
							break;
					}
					//printf("arg_cnt: %d\n", arg_cnt);
					//printf("case ARG_LIST exec0: %lf\n", exec(n->next[0]));	// expr
					//printf("case ARG_LIST exec1: %lf\n", exec(n->next[1]->next[0]));	// expr
					printf("");
					//printf("case ARG_LIST exec1: %lf\n", exec(n->next[1]->next[1]));	// expr
					Node* cur = n;
					Node* prev;
					//for(int i=0; i<n->op_cnt; i++) {
					for(int i=0; i<arg_cnt; i++) {
						prev = cur;
						cur = prev->next[0];
						stack[tail++] = exec(cur);
						//printf("enqueue %lf, tail %d\n", stack[tail-1], tail-1);
						cur = prev->next[1];

					}
					//printf("end while\n");
					return;
				case PARAM_LIST:
					//printf("case PARAM_LIST how many pars: %d\n", n->op_cnt);
					par_cnt = 0;
					Node* ccur2 = n;
					exec(n->next[1]);
					
					while(ccur2->next[1] != NULL) {
						par_cnt++;
						ccur2 = ccur2->next[1];
					}
					//printf("par_cnt: %d\n", par_cnt);
					if(par_cnt != arg_cnt){
						printf("Error: %d\n", yylineno);
					}
					//printf("%s\n", vars[n->next[0]->var_idx]);
					//printf("%s\n", vars[n->next[1]->next[0]->var_idx]);
					printf("");
					
					Node* cur2 = n;
					Node* prev2;
					//for(int i=0; i<n->op_cnt; i++) {
					for(int i=0; i<par_cnt; i++) {
						prev2 = cur2;
						cur2 = prev2->next[0];
						vals[cur2->var_idx] = stack[head++];	
						//printf("dequeue %lf, head %d\n", stack[head-1], head - 1);
						cur2 = prev2->next[1];
					}
				case STMT:
					return exec(n->next[0]);
				case STMT_LIST:
					exec(n->next[0]);
					exec(n->next[1]);
					return 0;
				case FUNC_DECL:
					//printf("case FUNC_DECL\n");
					exec(n->next[1]); // param_list
					exec(n->next[2]); // fstmt_list
					return exec(n->next[3]);
				case FSTMT_LIST:
					exec(n->next[0]);
					exec(n->next[1]);
				case ID_LIST:
					//printf("case ID_LIST");
					printf("");
					//printf("case ID_LIST\n");
				case EXPR_LIST:
					printf("");
					//printf("case EXPR_LIST\n");
					//exec(n->next[0]);		// expr
					//printf("case EXPR_LIST-1\n");
					//printf("%d\n", n->next[1]);
					//exec(n->next[1]);		// expr_list:
					//printf("case EXPR_LIST-2\n");


				
			}
	}
	return 0;
}

