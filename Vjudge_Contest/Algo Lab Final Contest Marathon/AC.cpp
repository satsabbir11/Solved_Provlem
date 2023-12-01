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
        int n = s.size();

        vector<int> freq(30);

        for (int i = 0; i < n; i++)
            freq[s[i] - 'A']++;

        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());

        int ans = n, m = freq.size();
        for (int i = 1; i <= min(n, 26); i++)
        {
            if (n % i)
                continue;
            int a = 0, b = 0;
            for (int j = 0; j < min(m, i); j++)
            {
                int diff = freq[j] - n / i;
                if (diff > 0)
                    a += diff;
                if (diff < 0)
                    b -= diff;
            }
            ans = min(ans, max(a, b));
        }
        cout << ans << endl;
    }
}
