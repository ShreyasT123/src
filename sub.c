#include <stdio.h>

void sumofsubset(int set[],int subset[],int n,int susbetsize,int total ,int index, int target){

    if (total==target)
    {   printf("\n");
        for (int i = 0; i < susbetsize; i++)
        {
            printf("%d\t",subset[i]);
        }
        
        return;
    }

    for (int i = index; i < n; i++)
    {
        if (total+set[i]<=target)
        {
            subset[susbetsize]=set[i];
            sumofsubset(set,subset,n,susbetsize+1,total+set[i],i+1,target);

        }
        
    }
    
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int target = 35;
    int n = sizeof(set) / sizeof(set[0]);
    int subset[n];

    printf("Subsets of the given set that sum to %d:\n", target);
    sumofsubset(set, subset, n, 0, 0, 0, target);

    return 0;
}