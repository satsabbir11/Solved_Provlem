#include <bits/stdc++.h>
using namespace std;

long long dx[] = {1, -1, 0, 0};
long long dy[] = {0, 0, 1, -1};

int n, m, p = 1;

void makeComponent(vector<vector<char>> &c, vector<vector<int>> &par, vector<int> &rk, int i, int j)
{
    par[i][j] = p;
    rk[p]++;
    for (int ii = 0; ii < 4; ii++)
    {
        int x = i + dx[ii], y = j + dy[ii];
        if (x <= 0 or x > n or y <= 0 or y > m or c[x][y] == '.' or par[x][y] != -1)
            continue;
        makeComponent(c, par, rk, x, y);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m; p=1;

        vector<vector<char>> c(n + 2, vector<char>(m + 2));
        vector<vector<int>> par(n + 2, vector<int>(m + 2, -1));
        vector<int> rk(n * m + 5, 0);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> c[i][j];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (c[i][j] == '#' and par[i][j] == -1)
                {
                    makeComponent(c, par, rk, i, j);
                    p++;
                }
            }

        int ans = 0;
        
        for (int i = 1; i <= n; i++)
        {
            map<int, bool> mp;
            int cnt = 0;
            for (int j = 1; j <= m; j++)
            {
                if (c[i][j] == '#' and !mp[par[i][j]])
                {
                    cnt += rk[par[i][j]];
                    mp[par[i][j]] = true;
                }
                else if (c[i][j] == '.')
                {
                    cnt++;
                    for (int ii = 0; ii < 4; ii++)
                    {
                        int x = i + dx[ii], y = j + dy[ii];
                        if (x <= 0 or x > n or y <= 0 or y > m or c[x][y] == '.' or mp[par[x][y]])
                            continue;
                        cnt += rk[par[x][y]];
                        mp[par[x][y]] = true;
                    }
                }
            }
            ans = max(ans, cnt);
        }
        for (int j = 1; j <= m; j++)
        {
            map<int, bool> mp;
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if (c[i][j] == '#' and !mp[par[i][j]])
                {
                    cnt += rk[par[i][j]];
                    mp[par[i][j]] = true;
                }
                else if (c[i][j] == '.')
                {
                    cnt++;
                    for (int ii = 0; ii < 4; ii++)
                    {
                        int x = i + dx[ii], y = j + dy[ii];
                        if (x <= 0 or x > n or y <= 0 or y > m or c[x][y] == '.' or mp[par[x][y]])
                            continue;
                        cnt += rk[par[x][y]];
                        mp[par[x][y]] = true;
                    }
                }
            }
            ans = max(ans, cnt);
        }
        cout<<ans<<endl;
    }
}