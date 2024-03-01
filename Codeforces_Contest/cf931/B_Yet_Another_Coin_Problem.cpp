#include <bits/stdc++.h>
using namespace std;


int req(int sum, vector<int> &dp)
{
    if(sum<0) return INT_MAX;
    if (dp[sum] != INT_MAX)
        return dp[sum];

    for (int coin : {15, 10, 6, 3, 1}){
        int prev = req(sum-coin, dp);
        if (sum >= coin and prev+1 < INT_MAX)
            dp[sum] = min(dp[sum], prev + 1);
    }
    return dp[sum];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int ans = INT_MAX;

        for (int i = 1; i <= 20; i++)
        {
            int cnt;
            int mx = 15 * i;
            if (n >= mx)
            {
                vector<int> dp(n % mx + 1, INT_MAX);
                dp[0] = 0;
                cnt = i * (n / mx) + req(n % mx, dp);
            }
            else
            {
                vector<int> dp(n + 1, INT_MAX);
                dp[0] = 0;
                cnt = req(n, dp);
            }
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
}