#include <bits/stdc++.h>
using namespace std;

int n, m;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int mx = 0;

void dfs(int i, int j, string c[], vector<vector<bool>> &vis)
{
    for (int k = 0; k < 8; k++)
    {
        int xx = i + dx[k], yy = j + dy[k];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m)
            continue;

        if (c[xx][yy] == '1' && !vis[xx][yy])
        {
            vis[xx][yy] = true;
            mx++;
            dfs(xx, yy, c, vis);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while (t--)
    {
        n = 0;
        string c[35];

        while (getline(cin, c[n]))
        {
            if (c[n][0] == '\0')
                break;
            n++;
        }

        m = c[0].size();
        int ans = 0;

        vector<vector<bool>> vis(35, vector<bool>(35, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < c[i].size(); j++)
            {
                if (!vis[i][j] && c[i][j] == '1')
                {
                    mx = 0;
                    vis[i][j] = true;
                    dfs(i, j, c, vis);
                    ans = max(ans, 1 + mx);
                }
            }
        }

        cout << ans << endl;
        if (t)
            cout << endl;
    }
}
