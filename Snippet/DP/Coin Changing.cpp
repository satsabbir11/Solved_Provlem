long long minNumberOfCoin(vector<long long> &v, long long val, long long n, vector<long long> &dp)
{
    cnt++;
    if (val == 0)
        return 0;
    if (val < 0)
        return LLONG_MAX;
    if (dp[val] != LLONG_MAX)
        return dp[val];

    long long ans = LLONG_MAX;

    for (long long i = 0; i < n; i++)
    {
        long long res = minNumberOfCoin(v, val - v[i], n, dp);
        if (res != LLONG_MAX)
            ans = min(ans, res + 1);
    }

    return dp[val] = ans;
}


int numberOfWays(int coins[], int n, int sum)
{

	int dp[sum + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = coins[i]; j <= sum; j++)
			dp[j] += dp[j - coins[i]];
	return dp[sum];
}