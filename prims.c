#include <stdio.h>
#include <limits.h>
#define V 5 // Number of vertices


int minkey(int key[] , int mstset[]){

    int min = INT_MAX,minindex;
    for (int v = 0; v < V; v++)
    {
        if (mstset[v]==0 && key[v]<min)
        {
            minindex=v;
            min = key[v];
        }
        
    }
    return minindex;
    
}


void printmst(int graph[][V],int parent[]){

    for (int i = 0; i < V; i++)
    {
    printf("Edge %d - %d Weight %d\n",parent[i],i,graph[i][parent[i]]);

    }
    
}


void primsMst(int graph[][V]){


    int parent[V];
    int key[V];
    int mstset[V];

    for (int i = 0; i < V; i++)
    {
        key[i]=INT_MAX;
        mstset[i]=0;
    }
    
    parent[0]=-1;
    key[0]=0;

    for (int i = 0; i < V-1; i++)
    {
        int u = minkey(key,mstset);
        mstset[u]=1;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstset[v]==0 && graph[u][v]<key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v]; 
            }
            
        }
        
    }
    printmst(graph,parent);
    
}


int main()
{
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    primsMst(graph);
    return 0;
}
