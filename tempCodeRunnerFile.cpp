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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m, x, y, k;
        cin >> n >> m >> x >> y >> k;

        long long ans = 0;

        if (k >= 4)
            ans = n * m - 1;
        else if (k == 3)
        {
            if (x == 1 and y == 1)
                ans = n * m - 1;
            else if (x == 1 and y == m)
                ans = n * m - 1;
            else if (x == n and y == 1)
                ans = n * m - 1;
            else if (x == n and y == m)
                ans = n * m - 1;
            else if(x==n or x==1) ans = n*m-1;
            else if(y==m or y==1) ans = n*m-1;
            else
            {
                ans = n*m - min({x, y, n - x+1, m - y+1}); // fix
            }
        }
        else if (k == 2)
        {
            if (x == 1 and y == 1)
                ans = n * m - 1;
            else if (x == 1 and y == m)
                ans = n * m - 1;
            else if (x == n and y == 1)
                ans = n * m - 1;
            else if (x == n and y == m)
                ans = n * m - 1;
            else if(x==n or x==1) ans = n*m - min({y, m - y + 1, n}); // fix
            else if(y==m or y==1) ans = n*m - min({x, n - x +1, m}); // fix
            else
            {
                ans = n*m - min({x*y, (n-x+1)*y, x*(m-y+1), (n-x+1)*(m-y+1), n, m}); // fix
            }
        }
        else if (k == 1)
        {
           // cout<<k<<endl;
            if (x == 1 and y == 1)
                ans = n * m - min(n, m);
            else if (x == 1 and y == m)
                 ans = n * m - min(n, m);
            else if (x == n and y == 1)
                 ans = n * m - min(n, m);
            else if (x == n and y == m)
                 ans = n * m - min(n, m);
            else if(x==n or x==1){
                ans = n*m - min(m, n*min(y, m-y+1));
            }
            else if(y==m or y==1) {
                ans = n*m - min(n, m*min(x, n-x+1));;
            }
            else
            {
                long long mn = min({x * m, (n - x +1) * m, n * y, n * (m - y + 1)});
                ans = n * m - mn;
                //cout<<mn<<endl;
            }
        }
        else
            ans = n * m - 1;

        cout << ans << endl;
    }
}