#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
#define ull unsigned long long
#define con (f ? "YES" : "NO")
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

#define dpos(n) fixed << setprecision(n)

#define clear1(a) memset(a, -1, sizeof(a))
#define clear0(a) memset(a, 0, sizeof(a))

#define sortn(a, x, n) sort(a + x, a + x + n)
#define sortv(s) sort(s.begin(), s.end())
#define reversev(s) reverse(s.begin(), s.end())
#define rsortv(s) sort(s.rbegin(), s.rend())
#define unik(a) unique(a.begin(), a.end()) - a.begin()
#define iotav(s, x) iota(s.begin(), s.end(), x)

#define lowerbound(v, x) lower_bound(v.begin(), v.end(), x) - v.begin()
#define upperbound(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()

#define pb push_back
#define loj(i, j) "Case " << i << ": " << j
#define gap " "

#define auto(x, a) for (auto &x : a)
#define print(x) cout << #x << " = " << x << endl

#define moveForward(current, ammount, mod) (amount - current) % mod
#define moveBackward(current, ammount, mod) (((amount - current) % mod) + mod) % mod

long long dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
long long dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k, mm = 1e9;
        cin >> n >> k;

        vector<long long> a(n), child(n, -1);
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i - 1];
            mm = min(mm, a[i - 1]);
        }

        if (k >= n - 1)
        {
            cout << n * mm << endl;
            continue;
        }

        while (k--)
        {
            long long mx = 0, in = 0;
            for (long long i = 0; i < n - 1; i++)
            {
                long long tem = mx;
                mx = max(mx, a[i] + a[i + 1] - 2 * min(a[i], a[i + 1]));
                if (mx > tem)
                    in = i;
            }
            long long cur = min(a[in], a[min(n - 1, in + 1)]);
            a[in] = a[min(n - 1, in + 1)] = cur;

            if (a[in] == cur)
            {
                a[min(n - 1, in + 1)] = cur;
                long long st = min(n - 1, in + 1);
                while (child[st] != -1)
                {
                    a[child[st]] = cur;
                    st = child[st];
                }
                child[in] = min(n - 1, in + 1);
            }
            else
            {
                a[in] = cur;
                long long st = in;
                while (child[st]!= -1)
                {
                    a[child[st]] = cur;
                    st = child[st];
                }
                child[min(n - 1, in + 1)] = in;
            }

            for (long long i = 1; i <= n; i++)
                cout << a[i - 1] << " ";
            cout << endl;
        }
        long long ans = 0;
        for (long long i = 1; i <= n; i++)
            ans += a[i - 1];
        cout << ans << endl;
    }
}