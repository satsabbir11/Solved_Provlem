#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

long long bigMod(long long n, long long m, long long p)
{
    if (m == 0)
        return 1;
    long long res = bigMod(n, m / 2, p);
    long long ans = (res % p * res % p) % p;
    if (m % 2)
        ans = (ans * n % p) % p;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n, m, p;

    while (cin >> n >> m >> p)
    {

        cout << bigMod(n, m, p) << endl;
    }
}