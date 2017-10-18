#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define KEY_SIZE	20	// Max size of search key
#define TABLE_SIZE	7	// size of hashing table
#define equal(e1,e2) (!strcmp(e1.key,e2.key))

typedef struct
{
    char key[KEY_SIZE];
} element;

struct list
{
    element item;
    struct list *link;
};
struct list *hash_table[TABLE_SIZE];

int hash_function(char *key)
{
 //fill in the blank
 int arr[20];
 int tmp[20];
 int i, j;
 int int_dec = transform(key); //transform into dec.
 int_dec *= int_dec; // square
 for(i = 1; int_dec > 0; i++){ // transform into binary
   tmp[i] = int_dec % 2;
   int_dec /= 2;
 }
 i--;
 for(j = 1; i > 0; i--, j++){
   arr[j] = tmp[i];
 }
 i = j;
 for(j = 1; j < i; j++){
   printf("%d", arr[j]);
 }
 // real key
 printf("\tkey : %d, %d, %d\n", arr[i / 2], arr[i / 2 + 1], arr[i / 2 + 2]);
 return arr[i / 2] * 4 + arr[i / 2 + 1] * 2 + arr[i / 2 + 2];
}

void hash_chain_find(element item, struct list *ht[])
{
 //fill in the blank
 hash_function(item.key);
 for(int i = 0; i < 7; i++){
   if(ht[i] == NULL)
    continue;
   if(ht[i]->item.key[0] == item.key[0]){
     printf("Find key(item.key: %s)\n", item.key);
     return ;
   }
 }
 printf("Can't fine key(item.key: %s)\n", item.key);
}

void hash_chain_print(struct list *ht[])
{
   struct list *node;
   int i;
   for(i=0;i<TABLE_SIZE;i++){
      printf("[%d] ->", i);
      for(node=ht[i]; node; node=node->link){
	     printf("%s->", node->item.key);
      }
      printf("\n");
   }
}

// invert search key into int
int transform(char *key)
{
	int number=0;
  // make simple plus natural number
	while(*key) number += *(key++);
	return number;
}

void hash_chain_add(element item, struct list *ht[])
{
   int hash_value = hash_function(item.key);
   struct list *ptr;
   struct list *node_before=NULL, *node = ht[hash_value];
   for(; node; node_before=node, node=node->link){
	  if(equal(node->item, item)){
                printf("input err\n");
                return;
      }
   }

ptr = (struct list *)malloc(sizeof(struct list));
ptr->item = item;
ptr->link = NULL;

if(node_before) node_before->link = ptr;
else ht[hash_value]=ptr;
}

int main()
{

	FILE* f;
	element tmp;
	char input[KEY_SIZE]=" ";
	f=fopen("input.txt","r");
	while(fscanf(f, "%s", &input) != EOF){
		strcpy(tmp.key, input);
		hash_chain_add(tmp, hash_table);
	}
	hash_chain_print(hash_table);

	strcpy(tmp.key, "x");
	hash_chain_find(tmp, hash_table);
	strcpy(tmp.key, "c");
	hash_chain_find(tmp, hash_table);

  return 0;
}
