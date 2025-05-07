#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int profit;
    float weight;
    float ptw;
    float part;
} Item;

int compare(const void *a, const void *b)
{

    Item *ai = (Item *)a;
    Item *bi = (Item *)b;
    return (ai->ptw < bi->ptw) ? 1 : -1;
}

void knapsack(Item items[], int n, int max, Item output[])
{
    int profit = 0;
    int capacity = max;
    int itemstaken = 0;
    for (int i = 0; i < n; i++)
    {
        items[i].ptw = (float)(items[i].profit / items[i].weight);
    }
    qsort(items, n, sizeof(Item), compare);
    for (int i = 0; i < n; i++)
    {
        if (items[i].weight < capacity)
        {
            profit += items[i].profit;

            output[i] = items[i];
            output[i].part = 1;
            capacity -= items[i].weight;
            itemstaken += 1;
        }
        else
        {
            float part = (float)(capacity / items[i].weight);
            output[i] = items[i];
            output[i].part = part;
            output[i].profit *= part;
            capacity = 0;
            itemstaken += 1;
        }
    }

    for (int i = 0; i < itemstaken; i++)
    {
        printf("Item %d profit %d part %f\n", output[i].id, output[i].profit, output[i].part);
    }
}

int main(int argc, char const *argv[])
{
    Item items[5] = {
        {1, 60, 10},
        {2, 100, 20},
        {3, 120, 30},
        {4, 30, 5},
        {5, 80, 40}};
    Item out[5];
    knapsack(items, 5, 80, out);
    return 0;
}
