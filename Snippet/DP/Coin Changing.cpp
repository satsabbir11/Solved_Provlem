long long minNumberOfCoin(vector<long long>&v, long long val, long long n, vector<long long>&dp){
    if(val==0) return 0;
    if(dp[val]!=-1) return dp[val];
 
    long long ans = LLONG_MAX;
 
    for(long long i=0;i<n;i++){
        if(v[i]<=val){
            long long subAns = coinChange(v, val-v[i], n, dp);
            if(subAns!=long long_MAX && subAns+1<ans) ans = subAns+1; 
        }
    }
 
    dp[val] = ans;
    return ans;
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