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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ull t;
    cin >> t;
    while (t--)
    {
        ull n;
        cin >> n;

        ull a[n + 2], cnt = 0, st = 2;
        for (ull i = 1; i <= n; i++) cin >> a[i];
        while (1)
        {
            cnt=0;
            for (ull i = 1; i <= n; i++)
            {
                if (a[i] % st == 0)
                    cnt++;
            }
            if(cnt==0 || cnt==n){
                st*=2;
                continue;
            }else{
                cout<<st<<endl;
                break;
            }
        }
    }
}