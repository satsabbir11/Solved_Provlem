#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    long long cum[200010] = {};

    for (long long i = 1; i <= 200005; i++)
    {
        cum[i] = i + cum[i - 1];
    }

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k, x;
        cin >> n >> k >> x;

        bool f = false;

        if ((n - k) >= 0)
            if ((cum[n] - cum[n - k]) >= x && (cum[k] <= x))
                f = true;
        cout << con << endl;
    }
}