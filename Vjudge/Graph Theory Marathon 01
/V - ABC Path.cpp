#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

char a[55][55];
int n, m;
int dp[55][55];

int dfs(int i, int j)
{
    if(dp[i][j]!=-1) return dp[i][j];

    int mx = 1;
    for (int k = 0; k < 8; k++)
    {
        int xx = i + dx[k], yy = j + dy[k];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m)
            continue;

        if ((a[i][j] + 1) == a[xx][yy])
        {
            mx = max(1 + dfs(xx, yy), mx);
        }
    }
    dp[i][j] = mx;
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int k=0;
    while (1)
    {
        cin >> n >> m;
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
                dp[i][j] = -1;
            }
        }

        int mx = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(a[i][j]=='A') mx = max(mx, dfs(i, j));
                //cout << a[i][j]<<" "<<i << " " << j << " " << cnt << endl;
            }
        }
        cout << loj(++k,mx) << endl;
    }
}
