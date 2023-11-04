#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int a, b, c, d, e, f;
int fn(int n, vector<int>&dp)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    if (n == 2)
        return c;
    if (n == 3)
        return d;
    if (n == 4)
        return e;
    if (n == 5)
        return f;

    if(dp[n]!=-1) return dp[n];
    
    dp[n] = (fn(n - 1, dp)%10000007 + fn(n - 2, dp)%10000007 + fn(n - 3, dp)%10000007 + fn(n - 4, dp)%10000007 + fn(n - 5, dp)%10000007 + fn(n - 6, dp)%10000007)%10000007;
    return dp[n];
}

int main()
{
    int n, cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno)
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        vector<int>dp(n+5, -1);
        printf("Case %d: %d\n", caseno, fn(n, dp) % 10000007);
    }
    return 0;
}