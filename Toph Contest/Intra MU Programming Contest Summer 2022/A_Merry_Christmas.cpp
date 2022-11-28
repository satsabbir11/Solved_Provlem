#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        long long a[m + 2] = {};

        for (long long i = 1; i <= n; i++)
        {
            long long s, k;
            cin >> s >> k;

            a[s]++;
            a[k + s]--;
        }

        for (long long i = 2; i <= m; i++) a[i] += a[i - 1];

        for (long long i = 1; i <= m; i++) cout << a[i] << " ";
        cout << endl;
    }
}