#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) {t=x; x=y; y=t;}
#define MAX_SIZE 10
#define NAME_SIZE 32

//adjust
void adjust(int heap[], int root, int n)
{
  int child, temp;
   temp = heap[root];   // 루트값저장
   child = 2 * root;      // 왼쪽 자식노드
   while(child <= n) {  // 마지막 노드까지 반복
      if(child < n && heap[child] < heap[child+1])   // 더 작은 자식 노드
         child++;
      if(temp>heap[child]) break;   // 부모노드와 자식노드 비교
      else  // 자식노드값을 부모노드로 복사
         heap[child / 2] = heap[child];
      child = child * 2;  // 한 레벨 아래로 이동
   }
   heap[child / 2] = temp;
}

//힙 정렬
void heap_sort(int list[], int n)
{
   int i, temp;
   int heap[MAX_SIZE + 1];

   for(i=0;i<n;i++)
      heap[i+1]=list[i];

   for(i=n/2;i>0;i--)     // 주어진 리스트를 최대히프로 변환
      adjust(heap,i,n);
   for(i=n-1;i>0;i--) {    // 루트노드와 마지막 노드 교환
      SWAP(heap[1], heap[i+1], temp);
      adjust(heap, 1, i);    // 축소된 리스트를 루트노드부터 재조정
   }
   for(i=0;i<n;i++)
      list[i]=heap[i+1];
}

int main()
{
   FILE *f;
   int i;
   int list1[MAX_SIZE];
   f= fopen("input2.txt","r");
   fscanf(f,"%d %d %d %d %d %d %d %d %d %d",
	   &list1[0],&list1[1],&list1[2],&list1[3],&list1[4],
	   &list1[5],&list1[6],&list1[7],&list1[8],&list1[9]);
   //힙 정렬
   heap_sort(list1, MAX_SIZE); /* 선택 정렬 호출 */
   printf("heap_sort: \n");
   for(i = 0; i < MAX_SIZE; i++)
    printf("%d \t", list1[i]);
   printf("\n");
   fclose(f);

   return 0;
}
