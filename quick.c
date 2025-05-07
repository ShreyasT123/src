#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
     *b = temp;
}

int partition(int arr[],int low,int high){

    int i = low-1;
    int pivot = arr[high];
    for(int j=low;j<high;j++){
        if (arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
        
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quicksort(int arr[],int low,int high){
    if (low<high)
    {
        int mid = partition(arr,low,high);
        quicksort(arr,low,mid-1);
        quicksort(arr,mid+1,high);

    }
    
}

int main(int argc, char const *argv[])
{
    int arr[] = {66,10,5,1,3,4,9,6};
    quicksort(arr,0,7);
    printf("\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d\t",arr[i]);
    }
    
    return 0;
}
