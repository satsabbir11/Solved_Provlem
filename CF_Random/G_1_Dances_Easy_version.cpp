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
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;

        long long a[n + 2], b[n + 2];
        a[1] = 1; // as they said c[i]1 = 1;
        for (long long i = 2; i <= n; i++)
            cin >> a[i];
        for (long long i = 1; i <= n; i++)
            cin >> b[i];

        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);

        int i = 1, j = 1, ans = 0;
        while (i <= n && j <= n)
        {
            if (a[i] >= b[j])
                ans++;
            else
                i++;
            j++;
        }

        cout << ans << endl;
    }
}