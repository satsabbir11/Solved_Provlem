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
long long a[1002][1002], vis[1002][1002], n, m;

long long dfs(long long i, long long j)
{
    long long cnt = a[i][j];
    vis[i][j] = 1;
    if (j < m && vis[i][j + 1] == 0 && a[i][j + 1])
    {
        cnt += dfs(i, j + 1);
    }
    if (i < n && vis[i + 1][j] == 0 && a[i + 1][j])
    {
        cnt += dfs(i + 1, j);
    }
    if (j > 1 && vis[i][j - 1] == 0 && a[i][j - 1])
    {
        cnt += dfs(i, j - 1);
    }
    if (i > 1 && vis[i - 1][j] == 0 && a[i - 1][j])
    {
        cnt += dfs(i - 1, j);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        for (long long i = 1; i <= n; i++)
            for (long long j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                vis[i][j] = 0;
            }

        long long mx = 0;

        for (long long i = 1; i <= n; i++)
            for (long long j = 1; j <= m; j++)
            {
                if (vis[i][j] == 0 && a[i][j])
                {
                    mx = max(mx, dfs(i, j));
                }
            }
        cout << mx << endl;
    }
}