#include <bits/stdc++.h>
using namespace std;
#define con (f ? "YES" : "NO")

int n;

void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> a)
{
    if (vis[i][j])
        return;
    //cout << i << " " << j << endl;
    vis[i][j] = true;
    if (i == 2 && j == n)
        return;

    if (i == 1)
    {
        int k = i + 1;
        if (a[k][j] == '>')
            dfs(k, j + 1, vis, a);
        if (a[k][j] == '<')
            dfs(k, j - 1, vis, a);
        if (j < n)
        {
            int k = j + 1;
            if (a[i][k] == '>')
                dfs(i, k + 1, vis, a);
            if (a[i][k] == '<')
                dfs(i, k - 1, vis, a);
        }
        if (j > 1)
        {
            int k = j - 1;
            if (a[i][k] == '>')
                dfs(i, k + 1, vis, a);
            if (a[i][k] == '<')
                dfs(i, k - 1, vis, a);
        }
    }
    if (i == 2)
    {
        int k = i - 1;
        if (a[k][j] == '>')
            dfs(k, j + 1, vis, a);
        if (a[k][j] == '<')
            dfs(k, j - 1, vis, a);
        if (j < n)
        {
            int k = j + 1;
            if (a[i][k] == '>')
                dfs(i, k + 1, vis, a);
            if (a[i][k] == '<')
                dfs(i, k - 1, vis, a);
        }
        if (j > 1)
        {
            int k = j - 1;
            if (a[i][k] == '>')
                dfs(i, k + 1, vis, a);
            if (a[i][k] == '<')
                dfs(i, k - 1, vis, a);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<char>> a(3, vector<char>(n + 1));

        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];

        vector<vector<bool>> vis(3, vector<bool>(n + 2, false));

        dfs(1, 1, vis, a);
        bool f = vis[2][n];
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}
