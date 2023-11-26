#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;

    vector<pair<long long, long long>> edges[n + 2];
    vector<long long> dist[n + 2];

    for (long long i = 0; i <= n; i++)
        for (long long j = 0; j <= 10; j++)
            dist[i].push_back(1e18);

    while (m--)
    {
        long long x, y, w;
        cin >> x >> y >> w;
        edges[x].push_back({y, w});
    }

    //dist[1][k - 1] = 0;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    pq.push({0, 1});

    while (!pq.empty())
    {
        long long u = pq.top().second, d = pq.top().first;
        pq.pop();

        if (dist[u][k - 1] < d)
            continue;

        for (auto e : edges[u])
        {
            long long w = e.second, v = e.first;

            if (dist[v][k - 1] > d + w)
            {
                dist[v][k - 1] = d + w;
                pq.push({dist[v][k - 1], v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }

    for (long long i = 0; i < k; i++)
        cout << dist[n][i] << " ";
}