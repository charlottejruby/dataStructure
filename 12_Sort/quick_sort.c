#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t)((t)=(x), (x)=(y), (y)=(t))

int partition(int list[], int left, int right){

    int low, high, pivot, temp;
    low=left;
    high=right+1;
    pivot= list[left];

    do{
        do
        {
            low++;
         } while (low<=right && list[low]<pivot);
        do{
            high--;
        }while(high>=left && list[high]>pivot);
        
        if(low<high)
            {
                temp=list[low];
                list[low]=list[high];
                list[high]=temp;
            }
    }while(low<high);
    temp=list[left];
    list[left]=list[high];
    list[high]=temp;
    return high;
}
void quick_sort(int list[], int left, int right){
    if(left<right){
        int q = partition(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
}
int main(){
        int list[MAX_SIZE];
        int i, n;
        n=MAX_SIZE;
        srand((unsigned)time(NULL));
        for(i=0; i<n;i++){
            list[i]=rand()%100;
        }
        quick_sort(list, 0, n-1);
        for(i=0;i<n;i++){
            printf("%d ", list[i]);
        }
        printf("\n");
        return 0;
}