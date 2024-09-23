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
        long long n;
        cin >> n;

        long long cum = 0;
        long long a[n + 2];
        for (long long i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            a[i] = x;
            cum += x;
        }

        sort(a + 1, a + 1 + n);

        long long x;

        if (n == 1 or n == 2)
        {
            cout << -1 << endl;
            continue;
        }

        long long l = 0, r = 1e15;
        long long i;
        
        if (n % 2 == 1)
            i = (n + 1) / 2;
        else
            i = n / 2 + 1;

        while (l < r)
        {
            long long mid = l + (r - l) / 2;
            double avg = ((double)cum + (double)mid) / (2.0 * (double)n);

            //cout<<i<<" "<<avg<<" "<<l<<" "<<r<<" "<<mid<<endl;

            if (avg > (double)a[i])
                r = mid;
            else
                l = mid + 1;
        }
        cout << r << endl;
    }
}