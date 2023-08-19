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
        long long n;
        cin >> n;

        map<long long, long long> mp;
        for (long long i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            mp[x]++;
        }

        long long q;
        cin >> q;
        while (q--)
        {
            long long b, c;
            cin >> b >> c;

            long long D = b * b - 4 * c;
            // cout<<b<<" "<<c<<endl;
            //cout<<D<<endl;

            long long sq = sqrt(D);
            bool f= (sq*sq==D);

            if (D < 0 || !f)
                cout << 0 << " ";
            else
            {
                long long x = (b + sqrt(D)) / 2;
                if (!D)
                {
                    x = mp[x];
                    long long x1 = x, x2 = x - 1;
                    if (x1 % 2)
                        x2 /= 2;
                    else
                        x1 /= 2;
                    cout << x1 * x2 << " ";
                }
                else
                {
                    long long x1 = x, x2 = c / x;
                    cout << mp[x1] * mp[x2] << " ";
                }
            }
        }
        cout << endl;
    }
}