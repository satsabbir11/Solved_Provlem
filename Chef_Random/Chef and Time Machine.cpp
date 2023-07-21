#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        m += k;

        int a[n], b[n + m];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];

            a[i] -= b[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        sort(a, a + n);
        sort(b, b + m);

        int i = n - 1, j = m - 1, ans = 0;

        while (i >= 0 && j >= 0)
        {
            if (a[i] >= b[j])
            {
                ans += (a[i] - b[j]);
                i--;
            }
            j--;
        }

        while (i >= 0)
            ans += a[i--];

        cout << ans << endl;
    }
}