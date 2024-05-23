#include <bits/stdc++.h>
using namespace std;

long long mul(long long a, long long b, long long p){
    return __int128(a)*b%p;
}

long long  bigMod(long long a, long long b, long long p)
{
    if (!b)
        return 1;
    long long req = bigMod(a, b / 2, p);
    req %= p;
    req = mul(req, req, p);
    if (b % 2)
        req = mul(req, a, p);
    return req%p;
}

int32_t main()
{
    long long a, b, p;
    cin >> a >> b >> p;
    cout << bigMod(a, b, p) << endl<< ((a % p) * (b % p)) % p << endl<< ((a % p) * bigMod(b, p - 2, p)) % p << endl;
}


