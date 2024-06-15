#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        deque<long long> d;
        for (long long i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            d.push_back(x);
        }

        while (d.size() > 1 and k > 0)
        {
            long long f = d.front(), l = d.back();
            long long mn = min(f, l);

            if (2 * mn <= k)
            {
                d.front() -= mn;
                d.back() -= mn;

                k -= 2 * mn;
            }
            else
            {
                d.front() -= (k + 1) / 2;
                d.back() -= k / 2;
                k = 0;
            }
            if (d.front() == 0)
                d.pop_front();
            if (d.back() == 0)
                d.pop_back();
        }

        long long ans = n - d.size();
        if (d.size() and k >= d.front())
            ans++;
        cout << ans << endl;
    }
}