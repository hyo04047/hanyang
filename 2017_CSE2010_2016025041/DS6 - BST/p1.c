#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct TreeNode{
	int key;
	struct TreeNode *left, *right;
}TreeNode;

void display(TreeNode *p){
	if(p != NULL){
		printf("(");
		display(p->left);
		printf("%d", p->key);
		display(p->right);
		printf(")");
	}
}

TreeNode *search(TreeNode *node, int key){
	while(node != NULL){
		if(key == node->key)
			return node;
		else if(key < node->key)
			node = node->left;
		else if(key > node->key)
			node = node->right;
	}
	return NULL;
}

void insert_node(TreeNode **root, int key){
	TreeNode *p, *q;
	TreeNode *n;
	p = *root;
	q = NULL;

	// if(tmp != NULL){
	// 	n = (TreeNode *)malloc(sizeof(TreeNode));
	// 	n->key = key;
	// 	n->left = NULL;
	// 	n->right = NULL;

	// 	TreeNode *save;

	// 	if(p == NULL)
	// 		*root = n;
		
	// 	else{
	// 		while(p != NULL){
	// 			if(n->key < q->key){
	// 				save = p;
	// 				p = q->left;
	// 				q = save;
	// 			}
	// 			else{
	// 				save = p;
	// 				p = q->right;
	// 				q = save;
	// 			}
	// 		}
	// 	}

	// 	if(n->key < p->key)
	// 		p->left = n;

	// 	else
	// 		p->right = n;
	// }

	while(p != NULL){
		if(key == p->key)
			return;
		q = p;
		if(key < p->key) 
			p = p->left;
		else 
			p = p->right;
	}

	n = (TreeNode *)malloc(sizeof(TreeNode));
	if(n == NULL)
		exit(1);

	if(q != NULL)
		if(key < q->key)
			q->left = n;
		else
			q->right = n;
	else
		*root = n;
}

int main(){
	TreeNode *root = NULL;
	TreeNode *tmp;
	insert_node(&root, 3);
	insert_node(&root, 2);
	insert_node(&root, 5);
	insert_node(&root, 1);
	insert_node(&root, 4);

	if(search(root, 5) != NULL)
		printf("Search Success : %d\n", search(root, 5)->key);

	// delete_node(root, 3);

	display(root);
	//tmp = search(root, 5);
	//if(tmp != NULL)
	//	printf("Search Success : %d\n", tmp->key);
}