#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        pair<long long, long long> a[n + 1];
        long long ans[n + 1];
        long long bSum = 0, fSum = 0;
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i].first;
            bSum += a[i].first;
            a[i].second = i;
        }

        sort(a + 1, a + n + 1);

        for (long long i = 1; i <= n; i++)
        {
            long long segment = a[i].first;
            fSum += segment;
            bSum -= segment;

            ans[a[i].second] = n + segment * (2 * i - n) - fSum + bSum;
        }
        for (long long i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}