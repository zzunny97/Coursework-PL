#include <stdio.h>
#include <stdarg.h>

#ifndef __GINKONODE__
#define __GINKONODE__
#define PLUS 0			// '+'
#define MINUS 1		// '-'
#define MUL 2		// '*'
#define DIV 3		// '/'
#define LES 4		// '<'
#define GRE 5		// '>'
#define LESQ 6		// '<='
#define GREQ 7		// '>='
#define EQ 8		// '=='
#define NEQ 9		// '!='
#define SET_EXPR 10 // SET
#define PRINTSTMT 11	// PRINT
#define IFSTMT 12		// IF
#define IFELSE 13	// IF-ELSE
#define PAR 14		// parenthesis
#define NEG 15		// negative !
#define VAR 16
#define NUM 17
#define SET_FUNC_CALL 18
#define FUNC_DECL 19
#define FUNC_CALL 20
#define FSTMT_LIST 21
#define PARAM_LIST 22
#define ID_LIST 23
#define ARG_LIST 24
#define EXPR_LIST 25
#define FUNC_NAME 26
#define ROOT 27
#define STMT 28
#define STMT_LIST 29
#define PROGRAM 30
#define FUNC_NAME_TMP 31
#define EXPR_LIST_TMP 32


typedef struct Node {
	int type;
	int op;
	int op_cnt;
	double val;
	int var_idx;
	struct Node* next[5];
}Node;

Node* new_node(int par_type, int par_op, int par_op_cnt, ...){
	va_list ap;
	Node* ret = (Node*)malloc(sizeof(Node));
	if(ret == NULL)
		yyerror("malloc failed\n");
	ret->type =	par_type;
	ret->op = par_op;
	ret->op_cnt = par_op_cnt;
	for(int i=0; i<5; i++)
		ret->next[i] = NULL;
	va_start(ap, ret->op_cnt);
	for(int i=0; i<ret->op_cnt; i++) {
		ret->next[i] = va_arg(ap, Node*);
	}
	va_end(ap);
	return ret;
}

Node* new_node_num(int par_type, int par_op, double par_val) {
	//printf("Func: new_node_num\n");
	Node* ret = (Node*)malloc(sizeof(Node));
	if(ret == NULL)
		yyerror("malloc failed\n");
	ret->type = par_type;
	ret->op = par_op;
	ret->val = par_val;
	for(int i=0; i<5; i++)
		ret->next[i] = NULL;
	//printf("Func: new_node_num end\n");
	return ret;
}

Node* new_node_var(int par_type, int par_op, int par_idx) {
	//printf("Func: new_node_var\n");
	Node* ret = (Node*)malloc(sizeof(Node));
	if(ret == NULL)
		yyerror("malloc failed\n");
	ret->type = par_type;
	ret->op = par_op;
	ret->var_idx = par_idx;
	for(int i=0; i<5; i++)
		ret->next[i] = NULL;
	//printf("Func: new_node_var end\n");
	return ret;
}

Node* new_node_func(int par_type, int par_op, int par_func_idx) {
	//printf("new_node_func start\n");
	Node* ret = (Node*)malloc(sizeof(Node));
	if(ret == NULL)
		yyerror("malloc failed\n");
	ret->type = par_type;
	ret->op = par_op;
	ret->var_idx = par_func_idx;
	for(int i=0; i<5; i++)
		ret->next[i] = NULL;
	//printf("new_node_func end\n");
	return ret;
}



#endif
