#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int getVal(int *dp, int *a, int s, int n)
{
    if (s > n + 1)
        return n;
    else if (s == n + 1)
        return 0;

    return dp[s];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n + 2];
        for (long long i = 1; i <= n; i++)
            cin >> a[i];

        int dp[n + 2];
        for (long long i = 1; i <= n + 1; i++)
            dp[i] = n;
            
        dp[n] = 1;
        for (int i = n - 1; i >= 1; i--)
        {
            dp[i] = min(dp[i + 1] + 1, getVal(dp, a, a[i] + 1 + i, n));
        }
        cout << dp[1] << endl;
    }
}