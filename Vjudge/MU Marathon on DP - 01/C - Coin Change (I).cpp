#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j
#define MOD 100000007

int recursion(int sum, int n, vector<int> &coin, vector<int> &freq, vector<vector<int>>&dp)
{
    if (n==-1)
        return 0;
    if (!sum)
        return 1;
        if(dp[sum][n]!=-1) return dp[sum][n];
    int ans = 0;
    for (int i = 1; i <= freq[n - 1]; i++)
    {
        if (i * coin[n - 1] <= sum)
            ans += recursion(sum - i * coin[n - 1], n - 1, coin, freq, dp)%MOD;
    }
    ans += recursion(sum, n - 1, coin, freq, dp)%MOD;
    dp[sum][n] = ans%MOD;
    return dp[sum][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t, f = 0;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        vector<int> coin, freq;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            coin.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq.push_back(x);
        }
        vector<vector<int>>dp(1005, vector<int>(55, -1));
        cout << loj(++f, recursion(k, n, coin, freq, dp)) << endl;
    }
}