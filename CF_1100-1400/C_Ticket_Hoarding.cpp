#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, k;
        cin >> n >> m >> k;

        long long a[n + 2];
        for (long long i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);

        long long ans = 0, extra = 0;
        for (long long i = 1; i <= n; i++)
        {
            long long val = min(m, k);
            ans += val * (a[i] + extra);
            extra += val;
            k -= val;
        }

        cout << ans << endl;
    }
}