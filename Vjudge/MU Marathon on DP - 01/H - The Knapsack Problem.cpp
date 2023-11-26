#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int knapSack(int W, int i, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (i < 0)
        return 0;
    if (dp[W][i] != -1)
        return dp[W][i];

    if (W < weight[i])
        dp[W][i] = knapSack(W, i - 1, profit, weight, dp);
    else
        dp[W][i] = max(knapSack(W, i - 1, profit, weight, dp), profit[i] + knapSack(W - weight[i], i - 1, profit, weight, dp));

    return dp[W][i];
}

void solve()
{
    int n, W;
    cin >> W >> n;

    vector<int> profit(n);
    vector<int> weight(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> profit[i];
    }

    vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
    cout << knapSack(W, n - 1, profit, weight, dp) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    solve();
}