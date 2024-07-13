class Solution {
public:
    int solve(int dp[10][2][10], string& s, int idx, bool tight, int cnt) {
        if (idx == s.size())
            return cnt;
        if (dp[idx][tight][cnt] != -1)
            return dp[idx][tight][cnt];

        int limit = (tight ? (s[idx] - '0') : 9), ans = 0;

        for (int i = 0; i <= limit; i++) {
            ans +=
                solve(dp, s, idx + 1, (tight && (i == limit)), cnt + (1 == i));
        }

        return dp[idx][tight][cnt] = ans;
    }

    int countDigitOne(int n) {
        int dp[10][2][10];
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        return solve(dp, s, 0, true, 0);
    }
};