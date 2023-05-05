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

        int mx = 0, ans = -1;

        int a[n + 2], b[n + 2];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        for (int i = 0; i < n; i++)
        {
            if ((i + a[i]) > m)
                continue;
            else
            {
                if (mx < b[i])
                {
                    ans = i + 1;
                    mx = b[i];
                }
            }
        }
        cout << ans << endl;
    }
}