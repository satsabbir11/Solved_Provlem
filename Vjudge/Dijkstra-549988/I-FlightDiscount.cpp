#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> edges[n + 2];
    vector<long long> dist1(n + 2, 1e18), dist2(n + 2, 1e18);

    while (m--)
    {
        long long x, y, w;
        cin >> x >> y >> w;
        edges[x].push_back({y, w});
        edges[y].push_back({x, w});
    }

    dist1[1] = 0;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    pq.push({0, 1});

    while (!pq.empty())
    {
        long long u = pq.top().second, d = pq.top().first;
        pq.pop();

        if (dist1[u] < d)
            continue;

        for (auto e : edges[u])
        {
            long long w = e.second, v = e.first;

            if (dist1[v] > dist1[u] + w)
            {
                dist1[v] = dist1[u] + w;
                pq.push({dist1[v], v});
            }
        }
    }

    dist2[n] = 0;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq2;

    pq2.push({0, n});

    while (!pq2.empty())
    {
        long long u = pq2.top().second, d = pq2.top().first;
        pq2.pop();

        if (dist2[u] < d)
            continue;

        for (auto e : edges[u])
        {
            long long w = e.second, v = e.first;

            if (dist2[v] > dist2[u] + w)
            {
                dist2[v] = dist2[u] + w;
                pq2.push({dist2[v], v});
            }
        }
    }

    long long ans = 1e18;
    for (long long i = 1; i <= n; i++)
    {
        for (auto x : edges[i])
        {
            long long u = i, v = x.first, w = x.second;
            ans = min(ans, dist1[u] + dist2[v] + w / 2);
        }
    }
    cout << ans << endl;
}