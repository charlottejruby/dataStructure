#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}
void init_queue(QueueType *q){
    q->front =q->rear = 0;
}
int is_empty(QueueType * q){
    return ((q->front)==(q->rear));
}
int is_full(QueueType *q){
    return((q->rear+1)%MAX_QUEUE_SIZE==q->front);
}
void enqueue(QueueType *q, element item){
    if(is_full(q)){
        error("queue is full");
    }
    q->rear=(q->rear+1)%MAX_QUEUE_SIZE;
    q->data[q->rear]=item;
}
element dequeue(QueueType *q){
    if(is_empty(q)){
        error("queue is empty");
    }
    q->front=(q->front+1)%MAX_QUEUE_SIZE;
    return q->data[q->front];
}
#define BUCKETS 10
#define DIGITS 4
void radix_sort(int list[], int n){
    int i, b, d, factor=1;
    QueueType queues[BUCKETS];

    for(b=0;b<BUCKETS;b++){
        init_queue(&queues[b]);
    }
    for(d=0;d<DIGITS;d++){          //데이터들을 자리수에 따라큐에 삽입
        for(i=0;i<n;i++){
            enqueue(&queues[(list[i]/factor)%10], list[i]);
        }
        for(b=i=0;b<BUCKETS;b++){   //버킷에서 꺼내어 list로 합친다.
            while(!is_empty(&queues[b])){
                list[i++]=dequeue(&queues[b]);
            }
        }
        factor*=10;
    }
}
#define SIZE 100

int main(){
    int list[SIZE];
    srand(time(NULL));
    for(int i = 0 ; i <SIZE;i++){
        list[i]=rand()%100;
    }
    radix_sort(list, SIZE);
    for(int i = 0 ; i < SIZE;i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}