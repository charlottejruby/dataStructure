#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode{
    element data;
    struct QueueNode * link;
}QueueNode;

typedef struct{
    struct QueueNode* front, *rear;
}LinkedQueueType;

void init(LinkedQueueType *q){
    q->front = q->rear =NULL;
}
int is_empty(LinkedQueueType *q){
    return (q->front==NULL);
}

void enqueue(LinkedQueueType *q, element data){
    QueueNode * temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->link = NULL;
    if(is_empty(q)){
        q->front = temp;
        q->rear = temp;
    }
    else{
        q->rear->link = temp;
        q->rear = temp;
    }

}
element dequeue(LinkedQueueType *q){
    element data;
    QueueNode *temp = q->front;
    if(is_empty(q)){
        fprintf(stderr, "queue is empty");
        exit(1);
    }
    else{
         data = temp->data;
         q->front = q->front->link;
         if(q->front == NULL)
            q->rear = NULL;
        free(temp);
        return data;
    }
}
void print_queue(LinkedQueueType *q){
    QueueNode *p;
    for(p=q->front;p!=NULL;p=p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}
int main(){
    LinkedQueueType queue;
    
    init(&queue);
    enqueue(&queue, 1);
    print_queue(&queue);
    enqueue(&queue, 2);
    print_queue(&queue);

    return 0;
}