#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;

void error(char* message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}
void init_queue(QueueType * q){
    q->front = q->rear = -1;
}

void queue_print(QueueType *q){
    for(int i = 0 ; i < MAX_QUEUE_SIZE;i++){
        if(i<=q->front || i>q->rear)
            printf("  | ");
        else
            printf("%d | ", q->data[i]);
    }
    printf("\n");
}

int is_full(QueueType *q){
    if(q->rear == MAX_QUEUE_SIZE-1)
        return 1;
    else
        return 0;
}
int is_empty(QueueType *q){
    if(q->rear == q->front){
        return 1;
    }
    else 
        return 0;
}

void enqueue(QueueType *q, int item){
    if(is_full(q)){
        error("queue is full");
        return;
    }
    else 
        q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q){
    int item;
    if(is_empty(q)){
        error("queue is emtpy");
        return -1;
    }
    else
        item = q->data[++(q->front)];
    return item;
}
int main(){
    int item = 0;
    QueueType q;

    init_queue(&q);
    enqueue(&q, 10);
    queue_print(&q);
    enqueue(&q, 20);
    queue_print(&q);

    return 0;
}