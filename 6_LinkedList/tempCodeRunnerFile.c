

int main(){
    ListNode * head = NULL;
    insert_first(head, 10);
    print_list(head);

    insert_first(head, 20);
    print_list(head);

    list_first(head, 30);
    print_list(head);

    list_search(head, 10);

    return 0;

}