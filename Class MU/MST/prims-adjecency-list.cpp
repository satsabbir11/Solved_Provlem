#include <bits/stdc++.h>
using namespace std;

int minCost(int n, int cost[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for(int i=0;i<n;i++){
        if(!mstSet[i] && cost[i]<min){
            min = cost[i];
            min_index = i;
        }
    }

    return min_index;
}

void printMST(int n, int parent[], vector<vector<pair<int, int>>>graph){
    cout<<"Node \t Parent Cost"<<endl;
    for(int i=1; i<n; i++){
        cout<<i<<" \t "<<parent[i]<<" \t "<<graph[i][parent[i]].second<<endl;
    }
}

void primMST(int n, vector<vector<pair<int, int>>>graph)
{
    int parent[n+2], cost[n+2];
    bool mstSet[n+2];

    for (int i = 0; i < n; i++)
    {
        cost[i] = INT_MAX;
        mstSet[i] = false;
    }

    parent[0] = -1;
    cost[0] = 0;

    for (int c = 0; c < n - 1; c++)
    {
        int u = minCost(n, cost, mstSet);
        mstSet[u] = true;

        for(auto i: graph[u]){
            int v = i.first;
            int w = i.second;

            if(cost[v]>w && !mstSet[v]){
                parent[v] = u;
                cost[v]= w;
            }
        }
        
    }

    printMST(n, parent, graph);
}

int main()
{
    int n, e;
    cin>>n>>e;
    
    vector<vector<pair<int, int>>>graph(n+2, vector<pair<int, int>>());

    for(int i=1; i<=e; i++){
        int x, y, w;
        cin>>x>>y>>w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    primMST(n, graph);
    return 0;
}


// 4 6
// 0 1 5
// 0 2 8
// 0 3 9
// 1 2 10
// 1 3 15
// 2 3 20
