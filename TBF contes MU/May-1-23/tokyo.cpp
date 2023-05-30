#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
#define endl "\n"
#define ull unsigned long long
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

#define lowerbound(v, x) lower_bound(v.begin(), v.end(), x) - v.begin() + 1
#define upperbound(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()

#define pb push_back
#define loj(i, j) "Case " << i << ": " << j
#define gap " "

#define auto(x, a) for (auto &x : a)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    t = 1;
    while (t--)
    {
        long long n;
        cin >> n;

        long long even = 0, odd = 0;

        vector<pair<long long, long long>> o, e, q;

        map<long long, bool> mp;

        long long a[n + 2];
        for (long long i = 1; i <= n; i++)
        {
            mp[i] = true;
            cin >> a[i];
            if (a[i] % 2)
            {
                odd++;
                o.push_back({a[i], i});
            }
            else
            {
                even++;
                e.push_back({a[i], i});
            }
            // cout<<a[i]<<" ";
        }

        sortv(o);
        sortv(e);

        long long l1 = o.size(), l2 = e.size();

        int k = 0, g = 0;

        for (int i = 1; i <= min(l1, l2); i++)
        {
           // cout<<a[i]<<" ";

            if (a[i] % 2)
            {
                cout << e[k].first << " ";
                a[e[k].second+1] = a[i];
                mp[e[k++].second] = false;
                //mp[i] = false;
            }
            else
            {
                cout << o[g].first << " ";
                a[o[g].second+1] = a[i];
                mp[o[g++].second] = false;
                //mp[i] = false;
            }
            //cout<<a[i]<<endl;
        }
        // cout<<mp[4]<<endl;
        for (long long i = 1; i <= n; i++)
        {
            if (mp[i])
            {
                cout << a[i] << " ";
            }
        }
    }
}