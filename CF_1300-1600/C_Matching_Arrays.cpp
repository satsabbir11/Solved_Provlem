#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define loj(i, j) "Case " << i << ": " << j

struct arr
{
    int fv, sv, in;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        long long a[n + 2];
        arr b[n + 2];

        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i].fv = a[i];
            b[i].in = i;
        }
        for (long long i = 0; i < n; i++)
        {
            cin >> b[i].sv;
        }

        sort(a, a + n);
        sort(b, b + n, [](arr x, arr y)
             { return x.sv < y.sv; });

        int j = n - k, cnt = 0;

        for (int i = 0; i < k; i++)
        {
            if (j == n)
                break;
            if (a[j++] > b[i].sv)
                cnt++;
        }

        j = 0;

        for (int i = k; i < n; i++)
        {
            if (a[j++] > b[i].sv)
                cnt++;
        }

        bool f = (cnt == k);

        cout << con << endl;

        if (f)
        {
            int ans[n + 2];
            int ff = 0;
            for (int i = k; i < n; i++) ans[ff++] = b[i].in;
            for (int i = 0; i < k; i++) ans[ff++] = b[i].in;
            sort(b, b + n, [](arr x, arr y)
                 { return x.in < y.in; });

            for (int i = 0; i < n; i++)
                cout << b[ans[i]].sv << " ";
            cout << endl;
        }
    }
}