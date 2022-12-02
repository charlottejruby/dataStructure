#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode * left, *right;
}TreeNode;

#define MAX_QUEUE_SIZE 100

typedef TreeNode * element;
//큐 타입
typedef struct{
    element data[MAX_QUEUE_SIZE]; //TreeNode 가리키는 타입의 stack
    int front, rear; //큐의 front, rear
}QueueType;

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}
void init_queue(QueueType *q){
    q->front = q->rear = 0;
}
int is_empty(QueueType * q){
    return (q->front == q->rear);
}
int is_full(QueueType * q){
    return ((q->rear+1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType *q, element item){
    if(is_full(q)){
        error("queue is full\n");
    }
    q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
    q->data[q->rear]=item;
}
element dequeue(QueueType *q){
    if(is_empty(q))
        error("queue is empty\n");
    q->front = (q->front+1)%MAX_QUEUE_SIZE;
    return q->data[q->front];
}

//ptr이 Tree라는 사실을 잊지 말기
void level_order(TreeNode *ptr){
    QueueType q;

    init_queue(&q);
    if(ptr==NULL)
        return;
    enqueue(&q, ptr);
    while(!is_empty(&q)){
        ptr = dequeue(&q);
        printf("%d ", ptr->data);
        if(ptr->left)
            enqueue(&q, ptr->left);
        if(ptr->right)
            enqueue(&q, ptr->right);
    }
}

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;
int main(){
    printf("level traversal >> ");
    level_order(root);
    printf("\n");
    return 0;
}