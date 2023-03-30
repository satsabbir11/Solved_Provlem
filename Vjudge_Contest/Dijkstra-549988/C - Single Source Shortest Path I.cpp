#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin >> n;
    t = n;

    vector<pair<int, int>> edges[n + 2];
    vector<long long> dist(n + 2, 1e18);

    while (t--)
    {
        int head, q;
        cin >> head >> q;

        while (q--)
        {
            int x, y;
            cin >> x >> y;
            edges[head].push_back({x, y});
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second, dis = pq.top().first;
        pq.pop();

        if (dist[u] < dis)
            continue;

        for (auto e : edges[u])
        {
            int w = e.second, v = e.first;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << i << " " << dist[i] << endl;
}