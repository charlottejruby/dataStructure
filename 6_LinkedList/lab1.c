#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char name[100];
}element;

typedef struct ListNode{
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value){
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}
void print_list(ListNode* head){
    ListNode* p = head;
    for(p = head ; p!=NULL;p=p->link){
        printf("%s->", p->data.name);
    }
    printf("NULL\n");
}

int main(){
    ListNode * head = NULL;
    element data;
    strcpy(data.name, "APPLE");
    head = insert_first(head, data);
    print_list(head);
    strcpy(data.name, "KIWI");
    head = insert_first(head, data);
    print_list(head);
     strcpy(data.name, "BANANA");
    head = insert_first(head, data);
    print_list(head);
}