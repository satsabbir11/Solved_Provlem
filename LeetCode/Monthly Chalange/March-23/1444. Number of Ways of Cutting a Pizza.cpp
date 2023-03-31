#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    int ways(vector<string> &pizza, int k)
    {
        int n = pizza.size(), m = pizza[0].size();

        vector<vector<int>> cum(n + 2, vector<int>(m + 2, 0));
        vector<vector<vector<int>>> dp(12, vector<vector<int>>(n + 2, vector<int>(m + 2, -1)));

        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                cum[i][j] = cum[i][j + 1] + cum[i + 1][j] - cum[i + 1][j + 1] + (pizza[i][j] == 'A' ? 1 : 0);

        return rec(0, 0, k - 1, n, m, dp, cum);
    }

    int rec(int r, int c, int k, int n, int m, vector<vector<vector<int>>> &dp, vector<vector<int>> &cum)
    {
        if (!cum[r][c])
            return 0;
        if (!k)
            return 1;

        if (dp[k][r][c] != -1)
            return dp[k][r][c];

        int ans = 0;

        for (int i = r + 1; i < n; i++)
            if (cum[r][c] - cum[i][c] > 0)
                ans = (ans + rec(i, c, k - 1, n, m, dp, cum)) % MOD;
        
        for (int i = c + 1; i < m; i++)
            if (cum[r][c] - cum[r][i] > 0)
                ans = (ans + rec(r, i, k - 1, n, m, dp, cum)) % MOD;

        return dp[k][r][c] = ans;
    }
};

int main()
{
    Solution s;

    vector<string> pizza = {"A..", "AAA", "..."};
    int k = 3;
    cout << s.ways(pizza, k) << endl;
}