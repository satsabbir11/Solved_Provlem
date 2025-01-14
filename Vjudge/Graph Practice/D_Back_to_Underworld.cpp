#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, tr, fl;

void dfs(int u, vector<vector<int>> &tree, vector<int>&color)
{
    for (int v : tree[u])
    {
        if (color[v]==-1)
        {
            color[v] = 1-color[u];

            if(color[v]==0) fl++;
            else tr++;

            dfs(v, tree, color);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t, tt = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> tree(20005);
        vector<int>color(20005, -1);

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        int ans=0;
        
        for (int i = 1; i <= 20000; i++)
        {
            if(color[i]!=-1 || tree[i].empty()) continue;
            tr = fl = 0;
            color[i]=0;
            fl++;
            dfs(i, tree, color);
            ans+=max(fl, tr);
        }
        
        cout << "Case " << tt++ << ": " << ans << endl;
    }
}
