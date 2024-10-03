#include <bits/stdc++.h>
using namespace std;


long long getB(long long n, long long b, long long c)
{
    long long ans = 0;
    if (n >= b) ans++;
    n -= b;
    b -= c;
    return max(ans, ans + (n / b));
}

long long get(long long n, long long a, long long b, long long c, bool f = true)
{
    long long ans = 0;

    if (f)
    {
        ans += getB(n, b, c);
        n = n - (ans * b) + (ans * c);
        ans += (n / a);
    }
    else
    {
        ans = n / a;
        n %= a;
        ans += getB(n, b, c);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    cout << max(get(n, a, b, c), get(n, a, b, c, false)) << endl;
}