#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, sum1=0, sum2=0;
        cin >> n;

        long long a[n + 2], b[n + 2];
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum1+=a[i];
        }
        for (long long i = 1; i <= n; i++)
        {
            cin >> b[i];
            sum2+=b[i];
        }

        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);

        cout<<min(sum1+n*b[1], sum2+n*a[1])<<endl;
    }
}