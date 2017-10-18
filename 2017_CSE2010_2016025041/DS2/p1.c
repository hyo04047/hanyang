#include <stdio.h>

void swap(int **a, int **b);

int main(){
	int A = 10, B = 20;
	int *ptr_A, *ptr_B;

	ptr_A = &A;
	ptr_B = &B;

	printf("Before A = %d\n", *ptr_A);
	printf("Before B = %d\n", *ptr_B);

	swap(&ptr_A, &ptr_B);

	printf("After A = %d\n", *ptr_A);
	printf("After B = %d\n", *ptr_B);

	return 0;
}

void swap(int **a, int **b){
	int *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}