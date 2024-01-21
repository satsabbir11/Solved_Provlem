#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
#define endl "\n"
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

long long dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
long long dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

struct info
{
    long long a, b;
};

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

        info v[n + 2];
        for (long long i = 1; i <= n; i++)
            cin >> v[i].a;
        for (long long i = 1; i <= n; i++)
            cin >> v[i].b;

        sort(v + 1, v + 1 + n, [](info x, info y)
             {
            if(x.b == y.b){
                return x.a>y.a;
            }else return x.b<y.b; });

        long long ans = k, val = 1, ind = -1;
        //for(long long i=1;i<=n;i++) cout<<v[i].b<<" ";
        for (long long i = 1; i <= n; i++)
        {
            if (v[i].b >= k)
            {
                ind = val;
                break;
            }
            long long tem = val;
            val = min(n, val + v[i].a);
            ans += (val - tem) * v[i].b;
           // cout<<ans<<" "<<val<<" "<<tem<<endl;
        }
        if (ind != -1)
            ans += (n - ind) * k;
        cout << ans << endl;
    }
}