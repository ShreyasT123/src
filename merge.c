#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left,int mid,int right){

    int n1 = mid-left+1;
    int n2 = right-mid;

    int leftarr[n1];
    int rightarr[n2];

    for (int i = 0; i < n1; i++)
    {
        leftarr[i] = arr[left+i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightarr[j] = arr[mid+j+1];
    }
    int i=0,j=0,k=left;
    while (i<n1 && j<n2)
    {
        if (leftarr[i]<rightarr[j])
        {
            arr[k]=leftarr[i];
            k++;
            i++;
        } else {
            arr[k]  = rightarr[j];
            k++;
            j++;
        }

        
    }

    while (i<n1)
    {
            arr[k]=leftarr[i];
            k++;
            i++;
        }
        while (j<n2)
    {
            arr[k]=rightarr[j];
            k++;
            j++;
        }
}

void mergersort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergersort(arr, left, mid);
        mergersort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {66,10,5,1,3,4,9,6};
    mergersort(arr,0,7);
    printf("\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d\t",arr[i]);
    }
    
    return 0;
}