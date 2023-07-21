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
        long long n, c, ans=0;
        cin >> n >> c;

        long long a[n + 2];
        for (long long i = 1; i <= n; i++)
            cin >> a[i];


        long long left = 1ll, right = 1e9;

        while (left <= right)
        {
            long long mid = left + (right-left) / 2ll;
            long long cnt = 0ll;

            for (long long j = 1; j <= n; j++)
            {
                cnt += ((2 * mid + a[j]) * (2 * mid + a[j]));
                if(cnt > c)
                {
                    right = mid - 1;
                    break;
                }
            }

            if (cnt <= c)
            {
                ans = mid;
                left = mid + 1;
            }
        }

        cout << ans << endl;
    }
}