#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<long long>> &a, vector<bool> &vis, vector<bool> &dfsVis, long long node)
{
    vis[node] = true;
    dfsVis[node] = true;

    for (long long x : a[node])
    {
        if (dfsVis[x]) return false;
        if (!vis[x] && !dfs(a, vis, dfsVis, x)) return false;
    }

    dfsVis[node] = false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        long long a[k + 2][n + 2];
        vector<vector<long long>> adj(n + 2);

        vector<bool> dfsVis(n + 2, false), vis(n + 2, false);

        for (long long i = 1; i <= k; i++)
        {
            for (long long j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                if (j >= 3)
                    adj[a[i][j - 1]].push_back(a[i][j]);
            }
        }

        bool f = true;
        for (long long i = 1; i <= n; i++)
            if (!vis[i])
                f &= dfs(adj, vis, dfsVis, i);

        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}