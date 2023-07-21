#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
#define endl "\n"
#define ull unsigned unsigned long long
#define con (f ? "YES" : "NO")

#define Dpos(n) fixed << setprecision(n)

#define CLR(a) memset(a, -1, sizeof(a))
#define CLN(a) memset(a, 0, sizeof(a))

#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
#define max4(a, b, c, d) max(a, max3(b, c, d))
#define min4(a, b, c, d) min(a, min3(b, c, d))
#define max5(a, b, c, d, e) max(max4(a, b, c, d), e)
#define min5(a, b, c, d, e) min(min4(a, b, c, d), e)

#define sortn(a, x, y) sort(a + x, a + x + y)
#define sortv(s) sort(s.begin(), s.end())
#define reversev(s) reverse(s.begin(), s.end())
#define reversesortv(s) \
    sortv(s);           \
    reversev(s)
#define unik(a) unique(a.begin(), a.end()) - a.begin()

#define lowerbound(v, x) lower_bound(v.begin(), v.end(), x) - v.begin() + 1
#define upperbound(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()

#define pb push_back
#define loj(i, j) "Case " << i << ": " << j
#define gap " "

#define auto(x, a) for (auto &x : a)

bool isSafeMultiply(unsigned long long a)
{
    return a <= 1e18 / a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    unsigned long long t;
    cin >> t;
    while (t--)
    {
        unsigned long long n, c;
        cin >> n >> c;

        unsigned long long a[n + 2];
        for (unsigned long long i = 1; i <= n; i++)
            cin >> a[i];

        sort(a + 1, a + 1 + n);

        unsigned long long aaa;

        unsigned long long left = 1ll, right = 1e18;

        while (left <= right)
        {
            unsigned long long mid = left + (right - left) / 2ll;

            unsigned long long ans = 0ll;

            bool f = true;

            for (unsigned long long j = 1; j <= n; j++)
            {

                ans += ((2 * mid + a[j]) * (2 * mid + a[j]));
            }

            if (f == false)
                continue;

            if (ans == c)
            {
                aaa = mid;
                break;
            }
            else if (ans < c)
                left = mid + 1;

            else
                right = mid - 1;
        }

        unsigned long long mid = 0;
        unsigned long long ans = 0;

        for (unsigned long long j = 1; j <= n; j++)
        {

            ans += ((2 * mid + a[j]) * (2 * mid + a[j]));
        }

        if (ans == c)
            aaa = mid;

        cout << aaa << endl;
    }
}