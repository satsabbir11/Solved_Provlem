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
        long long n, k;
        cin >> n >> k;

        long long a[n + 2], b[n + 2], c[n + 2], cnt1 = 0, cnt2 = 0, cnt3=0, in = n + 1;
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = c[i] = a[i];
        }

        for (long long i = 1; i <= n; i++)
        {
            if (a[i] > a[k])
            {
                in = i;
                break;
            }
        }

        swap(a[1], a[k]);

        for (long long i = 2; i <= n; i++)
        {
            if (a[i] > a[1])
                break;
            cnt2++;
        }

        if (in < k)
        {

            swap(b[in], b[k]);
            swap(in, k);

            for (long long i = max(1ll, k - 1); i <= n; i++)
            {
                if (b[i] > b[k])
                    break;
                else if (i != k)
                    cnt3++;
            }
        }

        //cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;

        cout << max({cnt2, cnt3}) << endl;
    }
}