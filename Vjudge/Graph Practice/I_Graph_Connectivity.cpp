#include <bits/stdc++.h>
using namespace std;

int convert(char x)
{
    return x - 'A' + 1;
}

void dfs(int u, vector<vector<int>> &ed, vector<int> &vis)
{
    vis[u] = true;
    for (int v : ed[u])
    {
        if (vis[v] == false)
            dfs(v, ed, vis);
    }
}

int main()
{
    int t;
    cin >> t;
    string str;

    getchar();
    getchar();

    while (t--)
    {
        int mx = -1;
        vector<vector<int>> v(28);
        vector<int> vis(28, false);

        while (getline(cin, str))
        {
            if (str.length() == 0)
            {
                break;
            }
            else if (str.length() == 1)
                mx = convert(str[0]);
            else
            {
                int x = convert(str[0]), y = convert(str[1]);
                v[x].push_back(y);
                v[y].push_back(x);
            }
            // cout<<str[0]<<endl;
        }

        int ans = 0;

        for (int i = 1; i <= mx; i++)
        {
            if (vis[i] == false)
                dfs(i, v, vis), ans++;
        }

        cout << ans << endl;
        if (t)
            cout << endl;
    }
}