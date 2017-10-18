#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 10
#define TABLE_SIZE 13
#define equal(e1, e2) (!strcmp(e1.key, e2.key))

typedef struct{
  char key[KEY_SIZE];
}element;

struct list{
  element item;
  struct list *link;
};

struct list *hash_table[TABLE_SIZE];

void hash_chain_print(struct list *ht[]){
  struct list *node;
  int i;
  for(i = 0; i < TABLE_SIZE; i++){
    printf("[%d] ->", i);
    for(node = ht[i]; node; node = node->link){
      printf(" %s ->", node->item.key);
    }
    printf("\n");
  }
}

int transform(char *key){
  int number = 0;
  while(*key)
    number += *(key++);
  return number;
}

int hash_function(char *key){
  return transform(key) % TABLE_SIZE;
}

void hash_chain_add(element item, struct lish *ht[]){
  int hash_value = hash_function(item.key);
  struct list *ptr;
  struct list *node_before = NULL, *node = ht[hash_value];
  for(; node; node_before = node, node = node->link){
    if(equal(node->item, item)){
      printf("Key is already in table.\n");
      return ;
    }
  }
  ptr = (struct list *)malloc(sizeof(struct list));
  ptr->item = item;
  ptr->link = NULL;

  if(node_before)
    node_before->link = ptr;
  else
    ht[hash_value] = ptr;
}

int main(){
  element tmp;
  strcpy(tmp.key, "a");
  hash_chain_add(tmp, hash_table);
  strcpy(tmp.key, "b");
  hash_chain_add(tmp, hash_table);
  strcpy(tmp.key, "c");
  hash_chain_add(tmp, hash_table);
  strcpy(tmp.key, "d");
  hash_chain_add(tmp, hash_table);
  strcpy(tmp.key, "e");
  hash_chain_add(tmp, hash_table);

  hash_chain_print(hash_table);
}
