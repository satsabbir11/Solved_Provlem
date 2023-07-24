#include <bits/stdc++.h>
using namespace std;
#define V 4

int minCost(int cost[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for(int i=0;i<V;i++){
        if(!mstSet[i] && cost[i]<min){
            min = cost[i];
            min_index = i;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V]){
    cout<<"Node \t Parent Cost"<<endl;
    for(int i=1; i<V; i++){
        cout<<i<<" \t "<<parent[i]<<" \t "<<graph[i][parent[i]]<<endl;
    }
}

void primMST(int graph[V][V])
{
    int parent[V], cost[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        cost[i] = INT_MAX;
        mstSet[i] = false;
    }

    parent[0] = -1;
    cost[0] = 0;

    for (int c = 0; c < V - 1; c++)
    {
        int u = minCost(cost, mstSet);
        mstSet[u] = true;

        for(int v = 0; v<V; v++){
            if(graph[u][v] && !mstSet[v] && cost[v]>graph[u][v]){
                parent[v]= u;
                cost[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {
        {0, 5, 8, 9},
        {5, 0, 10, 15},
        {8, 10, 0, 20},
        {9, 15, 20, 0},
    };

    primMST(graph);
    return 0;
}
