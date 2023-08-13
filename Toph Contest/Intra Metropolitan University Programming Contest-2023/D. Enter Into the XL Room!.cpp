#include <bits/stdc++.h>
using namespace std;

int knapSack(int w, int i, int *marks, int *cap, vector<vector<int>> &dp)
{
    if (i < 0)
        return 0;
    if (dp[i][w] != -1)
        return dp[i][w];

    if (cap[i] > w) dp[i][w] = knapSack(w, i - 1, marks, cap, dp);
    else dp[i][w] = max(marks[i] + knapSack(w - cap[i], i - 1, marks, cap, dp), knapSack(w, i - 1, marks, cap, dp));
    
    return dp[i][w];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, tot;
    cin >> n >> tot;

    int marks[n], cap[n];
    for (int i = 0; i < n; i++)
        cin >> marks[i];
    for (int i = 0; i < n; i++)
        cin >> cap[i];

    vector<vector<int>> dp(n, vector<int>(tot + 1, -1));

    cout << knapSack(tot, n - 1, marks, cap, dp) << endl;
}