#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct{
    element * data; //data끼리 연결해 주기 위해서 포인터로 선언
    int capacity;
    int top;

}StackType;

void init_stack(StackType *s){
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity *sizeof(element)); //data는 capacity 만큼 있어야하므로
}

void delete(StackType *s){
    free(s); //이미 주소 값으로 받아서 주소 값의 주소값처럼 사용할 필요가 없다.
}
int is_empty(StackType *s){
    return (s->top == -1);
}
int is_full(StackType *s){
    return (s->top == s->capacity -1);
}
void push(StackType *s, element item){
    if(is_full(s)){
        s->capacity*=2;
        s->data = (element *)realloc(s->data, s->capacity *sizeof(element));
    }
    s->data[++(s->top)] = item;
}
element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    else
        return s->data[(s->top)--];
}

int main(){
    StackType s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 10);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    return 0;
}
