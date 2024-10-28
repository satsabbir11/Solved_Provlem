#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n + 2];

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        for (int i = 1; i <= n / 2; i++)
        {
            if (a[i + 1] == a[i] || a[n - i] == a[n - i + 1])
                swap(a[i + 1], a[n - i]);
        }

        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            cnt += (a[i] == a[i + 1]);
        }

        cout << cnt << endl;
    }
}
