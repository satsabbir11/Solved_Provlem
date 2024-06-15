#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    t = 1;
    while (t--)
    {
        map<int, int> mp;
        bool f = true;
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[a[i]] += x;
        }

        int m;
        cin >> m;
        int b[m];
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            if ((mp[b[i]] - x) < 0)
                f = false;
            mp[b[i]] -= x;
        }
        if (!f)
        {
            cout << 0 << endl;
            continue;
        }

        f = true;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (mp[a[i]])
            {
                f = false;
                cnt++;
            }
        }
        long long res = 1;
        for (int i = 1; i <= cnt; i++)
        {
            res = ((res * 2) % 998244353);
        }
        cout << res << endl;
    }
}