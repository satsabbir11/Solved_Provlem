#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<vector<pair<long long, long long>>> edges(n + 2, vector<pair<long long, long long>>());
vector<long long> dist;

void dijkstra(long long u, long long w)
{
    if (dist[u] < w) //if node distance already saved is less than passing weight
        return;

    for (auto e : edges[u])
    {
        long long v = e.first;
        long long w = e.second;

        if (dist[v] > (dist[u] + w)) // if child distance is greater parent + to the child 
        {
            dist[v] = dist[u] + w; //update distance
            dijkstra(v, dist[v]); // passing node and distance untill nodes
        }
    }
}

int main()
{
    long long t;
    cin >> t;

    for (long long k = 1; k <= t; k++)
    {

        cin >> n >> m;

        edges.assign(n + 2, vector<pair<long long, long long>>());
        dist.assign(n + 2, 1e12);

        while (m--)
        {
            long long u, v, w;
            cin >> u >> v >> w;
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        }

        dist[1] = 0;
        dijkstra(1, 0); // Mainly passing node and distance untill nodes

        if (dist[n] == 1e12)
            cout << "Case " << k << ": Impossible" << endl;
        else
            cout << "Case " << k << ": " << dist[n] << endl;
    }
}