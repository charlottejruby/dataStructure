#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

void error(char* message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}
ListNode* insert_first(ListNode *head, int value){
    ListNode * p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}
//pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode *pre, element value){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}
ListNode* delete_first(ListNode * head){
    ListNode* removed = head;
    if(head == NULL)
        return NULL;
    head = removed->link;
    free(removed);
    return head;
}
//pre가 가리키는 다음 노드를 삭제한다
ListNode* delete(ListNode*head, ListNode* pre){
    ListNode * removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}
void print_list(ListNode *head){
    for(ListNode*p = head;p!=NULL;p=p->link){
        printf("%d->", p->data);
    }
    printf("NULL\n");
}
int main(){
    ListNode * head = NULL;

    for(int i = 0; i<5;i++){
        head = insert_first(head, i);
        print_list(head);
    }
    return 0;
}