#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

long long getSum(long long a, long long b)
{
    long long n = b - a + 1ll;
    long long sum = (n * (a + b)) / 2ll;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, x, y;
        cin >> n >> x >> y;

        long long gc = (x*y)/__gcd(x, y);
        gc = n / gc;

        x = n / x - gc;
        y = n / y - gc;
        //cout<<n-x<<endl;

        cout<<getSum(n-x+1, n)-getSum(1, y)<<endl;
    }
}