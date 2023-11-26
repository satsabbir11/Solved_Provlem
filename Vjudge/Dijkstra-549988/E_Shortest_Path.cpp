#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> edges(n + 2), dist(n + 2, vector<int>(n + 2, 1e8));
    map<pair<pair<int, int>, int>, bool> forbidden;
    queue<pair<pair<int, int>, long long>> q;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    while (k--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        forbidden[{{y, z}, x}] = true;
    }

    q.push({{n, 0}, 0});

    while (q.size())
    {
        int b = q.front().first.first, c = q.front().first.second, cost = q.front().second;
        q.pop();

        if (dist[b][c] <= cost)
            continue;
        dist[b][c] = cost;

        for (auto a : edges[b])
        {
            if (forbidden.count({{b, c}, a}))
                continue;
            q.push({{a, b}, cost + 1});
        }
    }

    int path = 1e8;

    for (auto x : dist[1])
        path = min(path, x);

    if (path == 1e8)
        cout << -1 << endl;
    else
    {
        cout << path << endl;
        int cur = 1;
        while (cur)
        {
            for (int i = 0; i <= n; i++)
            {
                if (dist[cur][i] == path)
                {
                    cout << cur << " ";
                    cur = i;
                    path--;
                }
            }
        }
    }
}