#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &ed, vector<int> &w, int par = -1)
{
    for (int v : ed[u])
    {
        if (v != par)
        {
            w[v] = w[u] + 1;
            dfs(v, ed, w, u);
        }
    }
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, st;
        cin >> n >> m;
        vector<vector<int>> ed(n + 2);
        vector<int> w(n + 2, -1);

        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;

            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        cin >> st;

        queue<int> q;
        q.push(st);
        w[st]=0;

        while (!q.empty())
        {
            int u = q.front(); q.pop();
            for (int v : ed[u])
            {
                if (w[v]==-1)
                {
                    w[v] = w[u] + 1;
                    q.push(v);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (i != st)
                cout << (w[i]!=-1 ? w[i] * 6 : -1) << " ";
        }
        cout << endl;
    }
}