#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void bubble_sort(int list[], int n){
    int i, j, temp;
    for(i=n-1;i>0;i--){
        for(j=0;j<i;j++){
            if(list[j]>list[j+1]){
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
}
int main(){
    int n, list[MAX_SIZE];
    n=MAX_SIZE;
    srand((unsigned)time(NULL));
    for(int i = 0 ; i < n ; i++){
        list[i]=rand()%100;
    }
    bubble_sort(list, n);
    for(int i = 0 ; i < n ; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}