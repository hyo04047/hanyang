#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE ];
	int front, rear;
}QueueType;

void init(QueueType *q);
void error(char *message);
int is_empty(QueueType *q);
int is_full (QueueType *q);
void enqueue( QueueType *q, element item );
element dequeue(QueueType *q);
element peek(QueueType *q);

int main(int argc, char *argv[])
{
	char command;
	FILE *input;
	element element_;
	QueueType *queue_ = (QueueType *)malloc(sizeof(QueueType));
	input = fopen(argv[1], "r");
	init(queue_);

	//read input file and call each function.
	while(1){
		command = fgetc(input);
		if(feof(input)) break;
		
		switch(command){
			case 'e':
					fscanf(input, "%d", &element_);
					enqueue(queue_, element_);
					break;
			case 'd':
					dequeue(queue_);
					break;
			case 'p':
					peek(queue_);
					break;
			default:
					;
		}
	}

	fclose(input);
	free(queue_);

    return 0;
}

//print error message
void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

//initialize front & rear and print it
void init(QueueType *q)
{
	q->front = 0;
	q->rear = 0;
	printf("init front = %d, rear = %d\n", q->front, q->rear);
}

//check whether the queue is empty or not
int is_empty(QueueType *q)
{
	if(q->front == q->rear)
		return 1;
	else
		return 0;
}

//check whether the queue is full or not
int is_full (QueueType *q)
{
	if(q->rear == q->front - 1)
		return 1;
	else
		return 0;
}

//if queue is full, call the error function
//else put the given item in the queue
void enqueue( QueueType *q, element item )
{
	if(is_full(q)){
		char* message = "Queue is full";
		error(message);
	}
	else{
		q->queue[(q->rear + 1) % MAX_QUEUE_SIZE] = item;
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		printf("enqueue() = %d\nfront = %d, rear = %d\n", item, q->front, q->rear);
	}
}

//if queue is empty, call the error function
//else pull out the earliest input
element dequeue(QueueType *q)
{
	if(is_empty(q)){
		char* message = "Queue is empty";
		error(message);
	}
	else{
		int tmp = q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
		q->queue[(q->front + 1) % MAX_QUEUE_SIZE] = 0;
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		printf("dequeue() = %d\nfront = %d, rear = %d\n", tmp, q->front, q->rear);
		return tmp;
	}
}

//same as dequeue, just check the item
element peek(QueueType *q)
{
	if(is_empty(q)){
		char* message = "Queue is empty";
		error(message);
	}
	else{
		printf("peek() = %d\n", q->queue[(q->front + 1) % MAX_QUEUE_SIZE]);
		return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
	}
}