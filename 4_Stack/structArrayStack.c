#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100
typedef struct{
    char name[MAX_STRING];
    char address[MAX_STRING];
}element;

element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty(){
    return (top==-1);
}
int is_full(){
    return(top==MAX_STACK_SIZE-1);
}
void push(element item){
    if(is_full()){
        fprintf(stderr,"stack is full\n");
    }
    else    stack[++top]=item;
}

element pop(){
 
        if(is_empty()){
            fprintf(stderr, "stack is empty");
            exit(1);
        }
        else
            return stack[top--];
}
element peek(){
     if(is_empty()){
            fprintf(stderr, "stack is empty");
            exit(1);
        }
        else
            return stack[top];
}

int main(){
    element hello= {"jimin", "jamsil"};
    push(hello);
    element out;

    out=pop();
    printf("%s %s", out.name, out.address);
    return 0;
}