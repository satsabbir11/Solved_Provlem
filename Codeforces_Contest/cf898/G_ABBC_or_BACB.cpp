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
        int n = s.size(), cnt = 0, sum = 0, mn = INT32_MAX;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
                cnt++;
            else
            {
                if (cnt)
                    mn = min(mn, cnt);
                sum += cnt;
                cnt = 0;
            }
        }
        sum += cnt;
        if (cnt)
            mn = min(mn, cnt);

        if (s[0] == 'B' || s[n - 1] == 'B')
        {
            cout << sum << endl;
            continue;
        }

        bool f = true;

        for (int i = 0; i < n - 1; i++)
            if (s[i] == s[i + 1] && s[i] == 'B')
            {
                f = false;
                break;
            }

        if (f)
            cout << sum - mn << endl;
        else
            cout << sum << endl;
    }
}