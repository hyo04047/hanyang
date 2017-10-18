#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct avl_node   {
    struct avl_node *left_child, *right_child;  /* Subtrees. */
    int data;                   /* Pointer to data. */
}avl_node;

struct avl_node *root;

//LL rotate
struct avl_node* rotate_right(struct avl_node *parent)
{
	struct avl_node *child = parent->left_child;
	parent->left_child = child->right_child;
	child->right_child = parent;
	return child;
}

//RR rotate
struct avl_node* rotate_left(struct avl_node *parent)
{
	struct avl_node *child = parent->right_child;
	parent->right_child = child->left_child;
	child->left_child = parent;
	return child;
}

//RL rotate
struct avl_node* rotate_right_left(struct avl_node *parent) 
{
	struct avl_node *child = parent->right_child;
	parent->right_child = rotate_right(child);
	return rotate_left(parent);
}

//LR rotate
struct avl_node* rotate_left_right(struct avl_node *parent)
{
	struct avl_node *child = parent->left_child;
	parent->left_child = rotate_left(child);
	return rotate_right(parent);
}

int get_height(struct avl_node *node)
{
	int height=0;
	if( node != NULL )
		height = 1 + max(get_height(node->left_child), get_height(node->right_child));
	return height;
}

int get_height_diff(struct avl_node *node) 
{
	if( node == NULL ) return 0;
	return get_height(node->left_child) - get_height(node->right_child);
} 

struct avl_node* rebalance(struct avl_node **node)
{
	int height_diff = get_height_diff(*node);
	if( height_diff > 1 ){
		if( get_height_diff((*node)->left_child) > 0 )
			*node = rotate_right(*node);
		else
			*node = rotate_left_right(*node);
	}
	else if ( height_diff < -1 ){
		if( get_height_diff((*node)->right_child) < 0 )
			*node = rotate_left(*node);
		else
			*node = rotate_right_left(*node);
	}
	return *node;
}

struct avl_node * avl_add(struct avl_node **root, int new_key)
{
	if( *root == NULL ){
		*root = (struct avl_node *)malloc(sizeof(struct avl_node));
		if( *root == NULL ){
			exit(1);
		}
		(*root)->data = new_key;
		(*root)->left_child = (*root)->right_child = NULL;
	}
	else if( new_key < (*root)->data ){
		(*root)->left_child = avl_add(&((*root)->left_child), new_key);
		*root = rebalance(root); 
	}
	else if( new_key > (*root)->data ){
		(*root)->right_child = avl_add(&((*root)->right_child), new_key);
		*root = rebalance(root);
	}
	else{
		printf("중복된 키\n");
		exit(1);
	}
	return *root;
}

void display(struct avl_node *node)
{
	if (node != NULL) {
		printf("(");
		display(node->left_child);
		printf("%d", node->data);
		display(node->right_child);
		printf(")");
	}
}

struct avl_node *avl_search(struct avl_node *node, int key) 
{ 
	if( node == NULL ) return NULL; 
	printf("%d ", node->data);
	if( key == node->data ) return node; 
	else if( key < node->data ) 
	   	return avl_search(node->left_child, key); 
	else 
		return avl_search(node->right_child, key); 
} 

void avl_delete_balance(struct avl_node **node){
	if(*node == NULL)
		return ;
	else{
		//using recursive rebalance at all node
		*node = rebalance(node);
		if((*node)->left_child != NULL)
			avl_delete_balance(&(*node)->left_child);
		if((*node)->right_child != NULL)
			avl_delete_balance(&(*node)->right_child);
	}
}

void avl_delete(struct avl_node **root, int key){
	avl_node *Parent;
	avl_node *Current;
	avl_node *Succ;
	avl_node *Succ_Parent;
	avl_node *Temp;

	Parent = NULL;
	Current = *root;

	//delete like binary search tree
	while(Current != NULL && Current->data != key){
		Parent = Current;
		Current = (key < Current->data) ? Current->left_child : Current->right_child;
	}

	if(Current == NULL){
		exit(1);
	}

	if(Current->left_child == NULL && Current->right_child == NULL){
		if(Parent != NULL){
			if(Parent->left_child == Current)
				Parent->left_child = NULL;
			else
				Parent->right_child = NULL;
		}
		else
			*root = NULL;
	}

	else if((Current->left_child == NULL && Current->right_child) || (Current->left_child && Current->right_child == NULL)){
		Temp = (Current->left_child != NULL) ? Current->left_child : Current->right_child;
		if(Parent != NULL){
			if(Parent->left_child == Current)
				Parent->left_child = Temp;
			else
				Parent->right_child = Temp;
		}
		else
			*root = Temp;
	}

	else{
		Succ_Parent = Current;
		Succ = Current->right_child;
		while(Succ->left_child != NULL){
			Succ_Parent = Succ;
			Succ = Succ->left_child;
		}
		if(Succ_Parent->left_child == Succ)
			Succ_Parent->left_child = Succ->right_child;
		else
			Succ_Parent->right_child = Succ->right_child;
		Current->data = Succ->data;
		Current = Succ;
		free(Current);
	}
	//rebalance
	avl_delete_balance(root);
}

int main()
{
	char command;
	int key;
	FILE *input;
	root = NULL;
	input = fopen("input.txt", "r");

	while (1) {
		command = fgetc(input);
		if (feof(input)) break;
		switch (command) {
		case 'i':
			fscanf(input, "%d", &key);
			avl_add(&root, key);
			break;
		case 'd':
			fscanf(input, "%d", &key);
			avl_delete(&root, key);
			break;
		default:
			break;
		}
	}
	
	display(root);
	printf("\n");

	return 0;
}