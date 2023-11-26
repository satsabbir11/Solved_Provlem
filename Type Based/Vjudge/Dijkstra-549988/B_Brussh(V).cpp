#include <bits/stdc++.h>
using namespace std;

#define loj(i, j) "Case " << i << ": " << j

int main()
{
    long long t, k = 1;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;

        vector<pair<long long, long long>> edges[n + 2];
        vector<long long> dist(n + 2, 1e12);

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
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[n] == 1e12)
            cout << "Case " << k << ": Impossible";
        else
            cout << loj(k, dist[n]);
        cout << endl;
        k++;
    }
}