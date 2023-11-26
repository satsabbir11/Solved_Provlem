#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size(), mn = INT32_MAX;

        for (int i = 0; i < 26; i++)
        {
            char c = 'a' + i;

            int mx = 0, cnt = 0;

            for (int j = 0; j < n; j++)
            {
                if (s[j] == c)
                {
                    mx = max(mx, cnt);
                    cnt = 0;
                }
                else
                    cnt++;
            }
            mx = max(cnt, mx);
            mn = min(mn, mx);
        }

        int ans = 0;
        while (mn > 0)
        {
            ans++;
            mn /= 2;
        }
        cout << ans << endl;
    }
}