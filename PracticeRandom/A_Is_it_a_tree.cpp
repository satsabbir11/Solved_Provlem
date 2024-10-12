#include <bits/stdc++.h>
using namespace std;
bool f=true;

void dfs(int u, vector<bool> &vis, vector<vector<int>>&p, int prev)
{
    if(vis[u]) {f=false; return;}
    vis[u] = true;
    for (int v: p[u]) if(prev!=v) dfs(v, vis, p, u);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>>p(n+2);

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;

        p[x].push_back(y);
        p[y].push_back(x);
    }

    vector<bool> vis(n + 2, false);
    dfs(1, vis, p, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] || !f)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}