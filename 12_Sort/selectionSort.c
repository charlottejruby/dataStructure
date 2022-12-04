#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n){
    int i, j, least, temp;
    for(i=0;i<n-1;i++){
        least=i;
        for(j=i+1;j<n;j++){
            if(list[j]<list[least])
                least=j;
        }
        temp=list[i];
        list[i]=list[least];
        list[least]=temp;
    }
}
int main(){
    int n, list[MAX_SIZE];
    n=MAX_SIZE;
    srand((unsigned)time(NULL));
    for(int i = 0 ; i <n;i++)
        list[i]=rand()%100;
    
    selection_sort(list, n);
    for(int i = 0 ; i<n;i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}