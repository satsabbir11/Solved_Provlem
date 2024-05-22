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

        vector<int> a(n), b(n);
        for (long long i = 1; i <= n; i++)
            cin >> a[i - 1];
        for (long long i = 1; i <= n; i++)
            cin >> b[i - 1];

        sort(a.rbegin(), a.rend());
        sort(b.begin(), b.end());

        int cnt = 0, in=n-1;

        for (int i = 0; i < n; i++)
        {
            if (a[in] > b[i])
            {
                a.push_back(b[i]);
                cnt++;
            }else in--;
        }
        cout << cnt << endl;
    }
}