#include <stdio.h>
#include <string.h>

#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void perm(char *list, int i, int n){
	int j, temp;
	
	if(i == n){
		for(j = 0; j <= n; j++)
			printf("%c", list[j]);
		printf("\n");
	}

	else{
		for(j = i; j <= n; j++){
			char temp;
			swap(list[i], list[j], temp);
			perm(list, i + 1, n);
			swap(list[i], list[j], temp);
		}
	}
}

int main(){

	char list;
	scanf("%s", &list);

	int n = strlen(&list);

	perm(&list, 0, n-1);

	return 0;
}