#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> p;
vector<long long> cnt;

void dfs(int u, int par)
{
    if (p[u].size() == 1 && p[u][0] == par)
        cnt[u] = 1;
    else
    {
        for (auto v : p[u])
        {
            if (v != par)
            {
                dfs(v, u);
                cnt[u] += cnt[v];
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        p.assign(n + 2, vector<int>());
        cnt.assign(n + 2, 0);

        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            p[x].push_back(y);
            p[y].push_back(x);
        }
        dfs(1, -1);

        int q;
        cin >> q;
        while (q--)
        {
            long long x, y;
            cin >> x >> y;
            cout << cnt[x] * cnt[y] << endl;
        }
    }
}