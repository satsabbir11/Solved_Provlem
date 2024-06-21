#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long h, n;
        cin >> h >> n;

        long long a[n + 2], b[n + 2];
        for (long long i = 1; i <= n; i++)
            cin >> a[i];
        for (long long i = 1; i <= n; i++)
            cin >> b[i];

        long long l = 1, r = 1e12;

        while (l < r)
        {
            long long turn = l + (r - l) / 2;
            long long hh = 0;
            for (long long i = 1; i <= n and hh <= h; i++)
            {
                hh += ((turn - 1) / b[i]) * a[i] + a[i];
            }

            if (hh >= h)
                r = turn;
            else
                l = turn + 1;
        }

        cout << l << endl;
    }
}

