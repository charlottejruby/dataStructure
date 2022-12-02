#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value){
    ListNode * p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

void list_search(ListNode* head, element value){
    for(ListNode * p = head; p!=NULL;p=p->link){
        if(p->data == value){
            printf("리스트에서  %d를 찾았습니다.", p->data);
            return;
        }
    }
        printf("리스트에서  %d를 찾지 못했습니다.", value);
}
void print_list(ListNode * head){
    for(ListNode* p = head;p!=NULL;p=p->link){
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

int main(){
    ListNode * head = NULL;
    head = insert_first(head, 10);
    print_list(head);

    head = insert_first(head, 20);
    print_list(head);

    head = insert_first(head, 30);
    print_list(head);

    list_search(head, 10);

    return 0;

}