#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

long long BIT[MAXN];

void update(long long idx, long long val, long long n)
{
    while (idx <= n)
    {
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}

long long query(long long idx)
{
    long long sum = 0;
    while (idx > 0)
    {
        sum += BIT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t, ii = 1;
    cin >> t;
    while (t--)
    {
        long long n, q;
        cin >> n >> q;

        long long a[n + 2];
        memset(BIT, 0, sizeof(BIT));

        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i];
            update(i, a[i], n);
        }

        cout << "Case " << ii++ << ": " << endl;

        while (q--)
        {
            long long ty;
            cin >> ty;
            if (ty == 1)
            {
                long long x;
                cin >> x;
                cout << a[x + 1] << endl;
                update(x + 1, -a[x + 1], n); // Subtract the old value
                a[x + 1] = 0; // Update the array with the new value
            }
            else if (ty == 3)
            {
                long long x, y;
                cin >> x >> y;
                cout << query(y + 1) - query(x) << endl;
            }
            else
            {
                long long x, y;
                cin >> x >> y;
                update(x + 1, y, n); // Add the new value
            }
        }
    }

    return 0;
}
