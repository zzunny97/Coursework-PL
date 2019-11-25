#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CHILD 10
#define TOKEN_SIZE 20
typedef struct {false, true} enum bool;

typedef struct Node{
	Node* childs[NUM_CHILD];
	Node* parent;
	int num_child;
	char* token;	
}Node;

void InitNode(Node* n, char* val) {
	n = (Node*)malloc(sizeof(Node));
	n->token = (char*)malloc(sizeof(char)*TOKEN_SIZE);
	n->num_child = 0;
	n->parent = NULL;
	int idx = 0;
	while(val[idx] != '\0') {
		if(idx == TOKEN_SIZE) {
			perror("token size is not enough");
			exit(-1);
		}
		n->token[idx] = val[idx];
		idx++;
	}
	for(int i=0; i<NUM_CHILD; i++)
		childs[i] = NULL;
}

void InsertNode(Node* par, Node* child) {
	if(child->parent != NULL) {
		perror("child node already has its parent\n");
		exit(-1);
	}
	par->childs[num_child++] = child;
}

void TraverseTree(Node* root) {
	TraverseTree(root->left);
	if(root != NULL && root->num_child == 0)
		printf("%s ", root->token);
	TraverseTree(root->right);
}
