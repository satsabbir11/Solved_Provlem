#include <bits/stdc++.h>
using namespace std;

#define loj(i,j) "Case "<<i<<": "<<j


int mx = 0, ind=-1;

void dfs(int u, vector<vector<pair<int, int>>> &p, int prev, vector<int> &dis)
{
    for (int i = 0; i < p[u].size(); i++)
    {
        int v = p[u][i].first;
        int w = p[u][i].second;
        if (prev != v)
        {
            dis[v] = dis[u] + w;
            int tem = mx;
            mx = max(mx, dis[v]);
            if (tem != mx)
                ind = v;
            dfs(v, p, u, dis);
        }
    }
}

int main()
{
    int k;
    cin >> k;
    for (int t = 1; t <= k; t++)
    {
        mx =0;
        int n;
        cin >> n;

        vector<vector<pair<int, int>>> p(n + 2);
        vector<int> dis(n + 2, 0);

        for (int i = 1; i < n; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;

            p[x].push_back(make_pair(y, w));
            p[y].push_back(make_pair(x, w));
        }

        dfs(0, p, -1, dis);

        mx = 0;

        dis.assign(n + 2, 0);

        dfs(ind, p, -1, dis);

        cout << loj(t, mx) << endl;
    }
}
