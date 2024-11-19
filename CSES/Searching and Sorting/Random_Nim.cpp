#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long bigMod(long long a, long long b)
{
    if (!b)
        return 1;
    long long res = bigMod(a, b >> 1);
    long long ans = (res * res) % MOD;
    if (b % 2)
        ans = (ans * a) % MOD;
    return ans;
}

long long inverseMod(long long a)
{
    return bigMod(a, MOD - 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d; cin>>n>>d;
        while (n--)
        {
            int x;
            cin >> x;
        }
        int x = d + 1, y = 2 * d;
        cout<<(x*inverseMod(y))%MOD<<endl; //x/y
    }
}