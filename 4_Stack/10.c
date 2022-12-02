#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct{
    element *data;
    int capacity;
    int top;
}StackType;

void init_stack(StackType *s){
    s->top = -1;
    s->capacity = 1;
    s->data = (element*)malloc(s->capacity*sizeof(element));
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == (s->capacity-1));
}

void push(StackType *s, element item){
    if(is_full(s)){
        s->capacity *=2;
        s->data = (element*)realloc(s->data, s->capacity*sizeof(element));
    }
    s->data[++(s->top)]=item;
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

    
    int n, x;
    StackType stack;
    init_stack(&stack);
    printf("정수를 배열의 크기\n");
    scanf("%d", &n);

    printf("정수를 입력하시오: ");
    for(int i = 0 ; i < n; i++){
        scanf("%d", &x);
        push(&stack, x);
    }

    printf("반전된 정수 배열: ");

    for(int i = 0 ; i < n; i++){
        printf("%d ", pop(&stack));
    }

    return 0;

}