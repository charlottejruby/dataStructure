#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct{
    element* data;
    int capacity;
    int top;
}StackType; 

void init_stack (StackType *s){
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(sizeof(element)* s->capacity);
}

void delete(StackType *s){
    free(s->data);
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == (s->capacity -1));
}

void push(StackType *s, element item){
    if(is_full(s)){
        s->capacity*=2;
        s->data = (element *)realloc(s->data, s->capacity*sizeof(element));
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "stack is empty\n");
        exit(1);
    }
    else
        return (s->data[(s->top)--]);
}

int check_matching(const char *in){
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);
    init_stack(&s);

    for(i = 0 ; i < n ; i ++){
        ch = in[i];
        switch(ch){
            case '(': case '[':case '{':
                push(&s, ch);
                break;
            case ')': case ']': case '}':
                if(is_empty(&s))
                    return 0; // 만약 스택이 비었으면 오류 
                else { //비지 않았다면 맞는 괄호인지 체크해야
                    open_ch = pop(&s);
                    if((open_ch == '(' && ch != ')')||(open_ch == '{' && ch != '}') || (open_ch == '[' && ch != ']'))
                        return 0; //맞는 괄호가 아니면 에러
                }
                break; //다시 for문을 돈다.
        }
    }
    if(!is_empty(&s))  //만약 비어있다면 return 1, 비어있지 않다면 return 0
        return 0;
    return 1;
}
int main(){
    char *p = "{A[(i+1)]=0;}";
    if(check_matching(p) == 1)
        printf("%s 괄호검사 성공 \n", p);
    else
        printf("%s 괄호검사 실패 \n", p);

    return 0;
}