#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 3;
const long long inf = 1e18;

vector<pair<long long, long long>> edges[N];
vector<long long> dist(N, inf);

int main()
{
    long long n, m;
    cin >> n >> m;

    while (m--)
    {
        long long x, y, w;
        cin >> x >> y >> w;
        edges[x].push_back({y, w});
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
                pq.push({dist[v], v});
            }
        }
    }

    for (long long i = 1; i <= n; i++)
        cout << dist[i] << " ";
}