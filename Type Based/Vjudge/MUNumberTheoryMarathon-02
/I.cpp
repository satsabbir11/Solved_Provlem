#include <bits/stdc++.h>
using namespace std;

long long bigMul(long long n, long long m, long long p)
{
  if(m<=0) return 0;
    long long res = bigMul(n, m/2, p);
    long long ans = (2*res)%p;
    if(m%2) ans = (ans+n)%p;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n, m, p;

    cin >> n >> m >> p;

    cout << bigMul(n%p, m%p, p) << endl;
}