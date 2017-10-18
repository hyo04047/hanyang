#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
} TreeNode;

//print all TreeNode keys
void display(TreeNode *p)
{
	if (p != NULL) {
		printf("(");
		display(p->left);
		printf("%d", p->key);
		display(p->right);
		printf(")");
	}
}

//find the node with key. binary search
TreeNode *search(TreeNode *node, int key)
{
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


void insert_node(TreeNode **root, int key) 
{
    TreeNode *p, *q; // p is current node, q is parent node
    TreeNode *n;      // n is new node
    p = *root;
    q = NULL;

    //search if key is in the node or not
    while (p != NULL){
        if(key == p->key) 
        	return;
        q = p;
        if( key < p->key ) p = p->left;
        else p = p->right;
    }

    // key isn't in the tree alloc new node and insert the key
    n = (TreeNode *) malloc(sizeof(TreeNode));
    if(n == NULL) 
    	return;

    // set the data
    n->key = key;
    n->left = n->right = NULL;

    //link with parent node
   if(q != NULL) 
       if( key < q->key ) q->left = n;
       else q->right = n;
   else *root = n;
}

int delete_node(TreeNode *node, int key)
{
	TreeNode *Current = node;
	TreeNode *Par_Parent = NULL;
	TreeNode *Parent = NULL;
	TreeNode *Child = NULL;
	TreeNode *Tmp_left = NULL;
	TreeNode *Tmp_right = NULL;

	int deleted = 0;

	// go to the node with the key
	while(Current->key != key){
		if(key > Current->key){
			Par_Parent = Parent;
			Parent = Current;
			Current = Current->right;
		}
		else{
			Par_Parent = Parent;
			Parent = Current;
			Current = Current->left;
		}
	}

	// if the node has no child
	if(Current->left == NULL && Current->right == NULL){
		deleted = Current->key;
		if(Parent->left == Current)
			Parent->left = NULL;
		if(Parent->right == Current)
			Parent->right = NULL;
		free(Current);
		return deleted;
	}

	// if the node has first child
	if(Current->left == NULL || Current->right == NULL){
		Child = (Current->left != NULL) ? Current->left : Current->right;
		// check current node is left node or right node of the child
		// and link the child to the parent node
		if(Parent->left == Current)
			Parent->left = Child;
		else
			Parent->right = Child;
		deleted = Current->key;
		free(Current);
		return deleted;
	}

	// if the node has second children
	if(Current->left != NULL && Current->right != NULL){
		Tmp_right = Current->right;
		// go to right node and there is no left child
		if(Tmp_right->left == NULL){
			Tmp_left = Current->left;
			Child = Tmp_right;
			if(Parent->right == Current){
				Parent->right = Child;
				Child->left = Tmp_left;
			}
			else if(Parent->left == Current){
				Parent->left = Child;
				Child->left = Tmp_left;
			}
			deleted = Current->key;
			free(Current);
			return deleted;
		}
		// go to right node and if there is left child
		// go to the minimum node
		while(Tmp_right->left != NULL){
			 Parent = Tmp_right;
			 Tmp_right = Tmp_right->left;
		}
		Parent->left = NULL;
		Current->key = Tmp_right->key;
	}
	return 0;
}


void main(int argc, char *argv[])
{
	char command;
	int key;
	FILE *input;
	TreeNode *root = NULL;

	// open the input file
	if (argc == 1) input = fopen("input.txt", "r");
	else input = fopen(argv[1], "r");

	while (1) {
		// scan the input command and call each function
		command = fgetc(input);
		if (feof(input)) break;
		switch (command) {
		case 'i':
			fscanf(input, "%d", &key);
			insert_node(&root, key);
			break;
		case 'd':
			fscanf(input, "%d", &key);
			delete_node(root, key);
			break;
		case 's':
			fscanf(input, "%d", &key);
			if (search(root, key) != NULL)printf("key is in the tree: %d\n", key);
			else printf("key is not in the tree: %d\n", key);
			break;
		case 'p':
			display(root);
            printf("\n");
			break;
		default:
			break;
		}
	}

	fclose(input);
}
