#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case #" << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    for (int kk = 1; kk <= t; kk++)
    {
        long long s, d, k;
        cin >> s >> d >> k;

        long long chess = s + 2 * d, patty = chess, bun = 2 * (s + d);

        bool f = false;

        if ((k + 1) <= bun && patty >= k && chess>=k)
            f = true;
        cout << loj(kk, con) << endl;
    }
}