vector<int> num;
int sz, k, n, m;
int dp[10][2][100][100];
int digitdp(int pos, int issmall, int sum, int val)
{
    if (pos == sz)
    {
        if (!sum && !val)
            return 1;
        return 0;
    }
    if (dp[pos][issmall][sum][val] != -1)
        return dp[pos][issmall][sum][val];
    int lim;
    if (issmall == 0)
        lim = num[pos];
    else
        lim = 9;
    int ans = 0;
    for (int digit = 0; digit <= lim; digit++)
    {
        int cur_issmall = issmall;
        if (issmall == 0 && digit < lim)
            cur_issmall = 1;
        int cur_sum = (sum + digit) % k;
        int cur_val = ((val * 10) + digit) % k;
        ans += digitdp(pos + 1, cur_issmall, cur_sum, cur_val);
    }
    return dp[pos][issmall][sum][val] = ans;
}

int solve(int n)
{
    num.clear();
    while (n > 0)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    sz = num.size();
    reverse(num.begin(), num.end());
    memset(dp, -1, sizeof(dp));
    return digitdp(0, 0, 0, 0);
}