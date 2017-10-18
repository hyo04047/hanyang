#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int n = 9;
int list[MAX_SIZE] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t));

void print(int list[], int n){
  int i;
  for(i = 0; i < n; i++)
    printf("%d ", list[i]);
  printf("\n");
}

int partition(int v[], int left, int right){
  int ipivot = (left + right) / 2;
  int store = -1;
  int i = 0;

  int swap = v[ipivot];
  v[ipivot] = v[right];
  v[right] = swap;

  store = left;

  for(int i = left; i < right; i++){
    if(v[i] <= v[right]){
      int tmp = 0;
      SWAP(v[i], v[store], tmp);
      store++;
    }
  }
  int tmp = 0;
  SWAP(v[store], v[right], tmp);

  return store;
}

void quick_sort(int list[], int left, int right){
  if(left < right){
    int q = partition(list, left, right);
    print(list, 9);
    quick_sort(list, left, q - 1);
    quick_sort(list, q + 1, right);
  }
}

int main(){
  quick_sort(list, 0, 8);

  return 0;
}
