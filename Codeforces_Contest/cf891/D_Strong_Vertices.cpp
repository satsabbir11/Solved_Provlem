#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1], b[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int mx = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            b[i] = a[i] - b[i];
            mx = max(mx, b[i]);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == mx)
                ans++;
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == mx)
                cout << i << " ";
        }
        cout << endl;
    }
}