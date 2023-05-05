#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n + 2][m + 2];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        long long ans = 0;

        for (int i = 0; i < m; i++)
        {
            int b[n + 2];
            for (int j = 0; j < n; j++)
                b[j] = a[j][i];
                
            sort(b, b + n);
            for (long long j = 0; j < n; j++)
                ans += b[j] * (2 * j - n + 1);
        }
        cout << ans << endl;
    }
}