#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> ed(n + 2); //store into x that, we need w to go y

    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        ed[x].push_back({w, y});
    }

    vector<int> dis(n + 2, LLONG_MAX); // w upto u
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //w upto u

    dis[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();

        if (w > dis[u]) continue; //that means, no its not correct we need dis[u], not w. so fuck off...

        for (auto [w, v] : ed[u])
        {
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << dis[i] << " ";
    cout << endl;
}