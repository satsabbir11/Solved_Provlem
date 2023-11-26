#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> edges[n + 2];
    vector<long long> dist(n + 2, 1e12), par(n + 2, -1);

    while (m--)
    {
        long long x, y, w;
        cin >> x >> y >> w;
        edges[x].push_back({y, w});
        edges[y].push_back({x, w});
    }

    dist[1] = 0;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    pq.push({0, 1});

    while (!pq.empty())
    {
        long long u = pq.top().second, d = pq.top().first;
        pq.pop();

        if (dist[u] < d)
            continue;

        for (auto e : edges[u])
        {
            long long w = e.second, v = e.first;

            if (dist[v] > dist[u] + w)
            {

                dist[v] = dist[u] + w;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    vector<long long> path;
    long long x = par[n];
    if (x != -1)
        path.push_back(n);
    else
        path.push_back(-1);

    while (x != -1)
    {
        path.push_back(x);
        x = par[x];
    }

    reverse(path.begin(), path.end());
    for (auto x : path)
        cout << x << " ";
}