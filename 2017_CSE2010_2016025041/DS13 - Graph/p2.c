#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 4
#define MAX_QUEUE_SIZE 10

int adj_mat[MAX_VERTICES][MAX_VERTICES] = {{0,1,0,1}, {1,0,1,1}, {0,1,0,1}, {1,1,1,0}};
int visited[MAX_VERTICES];
int n = 4;

typedef int element;
typedef struct{
  element queue[MAX_QUEUE_SIZE];
  int front, rear;
}QueueType;

void error(char *message){
  printf("%s\n", message);
  exit(1);
}

void init(QueueType *q){
  q->front = q->rear = 0;
}

int is_empty(QueueType *q){
  return (q->front == q->rear);
}

int is_full(QueueType *q){
  return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType *q, element item){
  if(is_full(q))
    error("Queue is full.");
  q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
  q->queue[q->rear] = item;
}

element dequeue(QueueType *q){
  if(is_empty(q))
    error("Queue is empty.");
  q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  return q->queue[q->front];
}

void graph_dfs_mat(int v){
  int w;
  QueueType q;
  init(&q);
  visited[v] = 1;
  printf("%d ", v);
  enqueue(&q, v);

  while(!is_empty(&q)){
    dequeue(&q);
    for(w = 0; w < n; w++){
      if(adj_mat[v][w] && !visited[w]){
        visited[w] = 1;
        enqueue(&q, w);
        printf("%d ", w);
      }
    }
  }
}

int main(){
  graph_dfs_mat(0);
  printf("\n");
  return 0;
}
