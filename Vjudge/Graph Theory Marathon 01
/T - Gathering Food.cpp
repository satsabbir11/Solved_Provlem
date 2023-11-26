#include <bits/stdc++.h>
using namespace std;

#define loj(i, j) "Case " << i << ": " << j

int n, ii, jj;
char final;
bool f;
int mx = 0;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

void dfs(int i, int j, char des, vector<vector<char>> &s, vector<vector<int>> &dis, vector<vector<int>> &vis)
{
    //cout<<i<<" "<<j<<" "<<des<<" "<<final<<" "<<dis[i][j]<<endl;

    for (int k = 0; k < 4; k++)
    {
        int xx = i + dx[k], yy = j + dy[k];
        if (xx < 0 || yy < 0 || xx >= n || yy >= n)
            continue;
        char v = s[xx][yy];
        // cout<<v<<endl;
        if (v <= des && v != '#' && dis[xx][yy] > (dis[i][j] + 1))
        {
            dis[xx][yy] = dis[i][j] + 1;
            if (v == des)
            {
                ii = xx;
                jj = yy;
                f = true;
                return;
            }
            dfs(xx, yy, des, s, dis, vis);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    for (int k = 1; k <= t; k++)
    {
        cin >> n;
        char final = 'A';

        vector<vector<char>> s(n, vector<char>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> s[i][j];
                if (s[i][j] == 'A')
                {
                    ii = i;
                    jj = j;
                }
                else if (s[i][j] != '#' && s[i][j] != '.' && final < s[i][j])
                {
                    final = s[i][j];
                }
            }
        }

        int ans = 0;
        f=false;

        for (char i = 'A'; i <= final; i++)
        {
            vector<vector<int>> vis(n, vector<int>(n, 0));
            vector<vector<int>> dis(n, vector<int>(n, 10000));
            f = false;
            dis[ii][jj] = 0;
            vis[ii][jj] = 1;
            dfs(ii, jj, i, s, dis, vis);
            if (!f)
            {
                cout << "Case " << k << ": Impossible" << endl;
                break;
            }
            //cout<<dis[ii][jj]<<endl;
            ans += dis[ii][jj];
        }

        if(final=='A') f=true;

        if (f)
            cout << loj(k, ans) << endl;
    }
}
