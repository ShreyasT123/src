#include <stdio.h>
#include <stdlib.h>

void swap(int * a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectsort(int arr[],int size){

    for(int i = 0;i<size;i++){
        int min = i;
        for(int j=i;j<size;j++){
            if (arr[min]>arr[j])
            {
                min = j;
            }
            
        }
        swap(&arr[min],&arr[i]);
        
    }

}

int main(){
    int arr[] = {66,10,5,1,3,4,9,6};
    selectsort(arr,8);
    printf("\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d\t",arr[i]);
    }
    
}
