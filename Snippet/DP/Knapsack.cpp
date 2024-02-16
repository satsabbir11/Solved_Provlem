long long knapSack(long long w, long long i, long long *marks, long long *cap, vector<vector<long long>> &dp)
{
    if (i < 0)
        return 0;
    if (dp[i][w] != -1)
        return dp[i][w];

    if (cap[i] > w) dp[i][w] = knapSack(w, i - 1, marks, cap, dp);
    else dp[i][w] = max(marks[i] + knapSack(w - cap[i], i - 1, marks, cap, dp), knapSack(w, i - 1, marks, cap, dp));
    
    return dp[i][w];
}