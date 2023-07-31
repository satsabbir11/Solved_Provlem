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
#define unik(a) unique(a.begin(), a.end()) - a.begin()

#define lowerbound(v, x) lower_bound(v.begin(), v.end(), x) - v.begin() + 1
#define upperbound(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()

#define pb push_back
#define loj(i, j) "Case " << i << ": " << j

#define auto(x, a) for (auto &x : a)

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

        long long a[n + 2], mx = 0;
        for (long long i = 1; i < n; i++)
        {
            cin >> a[i];
            mx = max(a[i], mx);
        }

        long long maxSum = (n * (n + 1)) / 2;

        if (maxSum < mx)
        {
            cout << "NO" << endl;
            continue;
        }
        else if (maxSum != mx)
        {
            a[n] = maxSum;
            map<long long, long long> mp;
            mp[a[1]]++;
            for (long long i = 2; i <= n; i++)
                mp[a[i] - a[i - 1]]++;
            bool f = true;
            for (long long i = 1; i <= n; i++)
            {
                if (mp[i] != 1)
                {
                    f = false;
                    break;
                }
            }
            cout << con << endl;
        }
        else
        {
            vector<long long> p;
            map<long long, long long> mp;
         
            for (long long i = 1; i < n; i++)
            {
                long long gp = a[i];
                if(i!=1) gp -= a[i - 1];
                mp[gp]++;
               
                if (gp > n || mp[gp] >= 2)
                    p.push_back(gp);
            }
            long long sz = p.size();
            if (sz != 1)
                cout << "NO" << endl;
            else
            {
                long long sm = p[0];
                for (long long i = 1; i <= n; i++)
                {
                    if (!mp[i])
                        sm -= i;
                }
                bool f = !sm;
                cout << con << endl;
            }
        }
    }
}