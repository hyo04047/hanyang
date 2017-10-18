#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef int element;
typedef struct _TreeNode
{
	element data;
	struct _TreeNode * left;
	struct _TreeNode * right;
} TreeNode;

//allocate memory for new node
TreeNode * createTreeNode(void)
{
	TreeNode *tmp;
	tmp = (TreeNode *)malloc(sizeof(TreeNode));
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

//save data into node
void setData(TreeNode * node, element data)
{
	node->data = data;
}


// "We can make node with this method too"
// void insert_node(TreeNode **root, int key){
// 	TreeNode *p, *q;
// 	TreeNode *n;
// 	p = *root;
// 	q = NULL;

// 	while(p != NULL){
// 		if(key == p->key)
// 			return;
// 		q = p;
// 		if(key < p->key) 
// 			p = p->left;
// 		else 
// 			p = p->right;
// 	}

// 	n = (TreeNode *)malloc(sizeof(TreeNode));
// 	if(n == NULL)
// 		exit(1);

// 	if(q != NULL)
// 		if(key < q->key)
// 			q->left = n;
// 		else
// 			q->right = n;
// 	else
// 		*root = n;
// }

//return saved data
element getData(TreeNode * node)
{
	return node->data;
}

//connect node to subtree
void makeLeftSubTree(TreeNode * main, TreeNode * sub)
{
	if(main->left != NULL)
		exit(1);
	else
		main->left = sub;
}

void makeRightSubTree(TreeNode * main, TreeNode * sub)
{
	if(main->right != NULL)
		exit(1);
	else
		main->right = sub;
}

//get pointer of subtree
TreeNode * getLeftSubTree(TreeNode * node)
{
	return node->left;
}

TreeNode * getRightSubTree(TreeNode * node)
{
	return node->right;
}

//print data inorder with recursive method
void printInorder(TreeNode *root){
	if(root != NULL){
		printInorder(root->left);
		printf("%d ", root->data);
		printInorder(root->right);
	}
}

//print data preorder with recursive method
void printPreorder(TreeNode *root){
	if(root != NULL){
		printf("%d ", root->data);
		printPreorder(root->left);
		printPreorder(root->right);
	}
}

//print data postorder with recursive method
void printPostorder(TreeNode *root){
	if(root != NULL){
		printPostorder(root->left);
		printPostorder(root->right);
		printf("%d ", root->data);
	}
}

int main(int argc, char *argv[]){
	FILE *input;
	input = fopen(argv[1], "r");
	char command;

	//create binary tree and set data
	TreeNode *root = createTreeNode();

	TreeNode *t1 = createTreeNode();
	TreeNode *t2 = createTreeNode();
	TreeNode *t3 = createTreeNode();
	TreeNode *t4 = createTreeNode();
	TreeNode *t5 = createTreeNode();
	TreeNode *t6 = createTreeNode();
	TreeNode *t7 = createTreeNode();
	TreeNode *t8 = createTreeNode();
	TreeNode *t9 = createTreeNode();
	setData(root, 54);
	setData(t1, 27);
	setData(t2, 89);
	setData(t3, 13);
	setData(t4, 44);
	setData(t5, 71);
	setData(t6, 92);
	setData(t7, 1);
	setData(t8, 37);
	setData(t9, 64);
	makeLeftSubTree(root, t1);
	makeLeftSubTree(t1, t3);
	makeLeftSubTree(t3, t7);
	makeRightSubTree(t1, t4);
	makeRightSubTree(t4, t8);
	makeRightSubTree(root, t2);
	makeRightSubTree(t2, t6);
	makeLeftSubTree(t2, t5);
	makeLeftSubTree(t5, t9);
	// insert_node(root, 54);
	// insert_node(root, 27);
	// insert_node(root, 89);
	// insert_node(root, 13);
	// insert_node(root, 44);
	// insert_node(root, 1);
	// insert_node(root, 37);
	// insert_node(root, 71);
	// insert_node(root, 92);
	// insert_node(root, 64);

	while(1){
		command = fgetc(input);
		if(feof(input)) break;
		switch(command) {
			case 'i': 
				printf("Inorder:   ");
				printInorder(root); 
				printf("\n");
				break;
			case 'r':
				printf("Preorder:  "); 
				printPreorder(root); 
				printf("\n");
				break;
			case 'o':
				printf("Postorder: "); 
				printPostorder(root); 
				printf("\n");
				break;
			default:
				break;
		}
	}

	fclose(input);
	free(root);
    return 0;
}