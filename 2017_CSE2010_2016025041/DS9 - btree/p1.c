#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_KEYS (1024)

struct btNode{
	int isLeaf;
	int numKeys;
	int keys[MAX_KEYS];
	struct btNode *kid[MAX_KEYS + 1];
};

typedef struct btNode *bTree;

bTree btCreate(void){
	bTree b;

	b = (bTree)malloc(sizeof(*b));
	assert(b);

	b->isLeaf = 1;
	b->numKeys = 0;

	return b;
}

void btDestroy(bTree b){
	if(!b->isLeaf){
		for(int i = 0; i < b->numKeys + 1; i++)
			btDestroy(b->kid[i]);
	}

	free(b);
}

void btPrintKeys(bTree p){
	int i;
	for(i = 0; i < p->numKeys; i++){
		if(p->isLeaf == 0)
			btPrintKeys(p->kid[i]);
		printf("(leaf : %d key : %d)\n", p->isLeaf, p->keys[i]);
	}
	if(p->isLeaf == 0)
		btPrintKeys(p->kid[i]);
}

int searchKey(int n, const int *a, int key){
	int lo;
	int hi;
	int mid;

	lo = -1;
	hi = n;

	while(lo + 1 < hi){
		mid = (lo + hi) / 2;
		if(a[mid] == key){
			return mid;
		}
		else if(a[mid] < key){
			lo = mid;
		}
		else{
			hi = mid;
		}
	}

	return hi;
}

int btSearch(bTree b, int key){
	int pos;

	if(b->numKeys == 0)
		return 0;

	pos = searchKey(b->numKeys, b->keys, key);

	if(pos < b->numKeys && b->keys[pos] == key)
		return 1;
	else{
		return (!b->isLeaf && btSearch(b->kid[pos], key));
	}
}

int main(){
	bTree b, c, d, e;
	int i = 0;

	b = btCreate();
	c = btCreate();
	d = btCreate();
	e = btCreate();

	b->isLeaf = 0;
	b->keys[0] = 2;
	b->keys[1] = 4;
	b->numKeys = 2;

	b->kid[0] = c;
	b->kid[1] = d;
	b->kid[2] = e;

	c->isLeaf = 1;
	c->keys[0] = 1;
	c->numKeys = 1;

	d->isLeaf = 1;
	d->keys[0] = 3;
	d->numKeys = 1;

	e->isLeaf = 1;
	e->keys[0] = 7;
	e->keys[1] = 8;
	e->numKeys = 2;

	btPrintKeys(b);
	printf("find : %d\n", btSearch(b, 4));
	btDestroy(b);

	return 0;
}