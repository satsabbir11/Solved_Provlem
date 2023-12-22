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

#define CLR1(a) memset(a, -1, sizeof(a))
#define CLR0(a) memset(a, 0, sizeof(a))

#define sortn(a, x, n) sort(a + x, a + x + n)
#define sortv(s) sort(s.begin(), s.end())
#define reversev(s) reverse(s.begin(), s.end())
#define rsortv(s) sort(s.rbegin(), s.rend())
#define unik(a) unique(a.begin(), a.end()) - a.begin()

#define lowerbound(v, x) lower_bound(v.begin(), v.end(), x) - v.begin()
#define upperbound(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()

#define pb push_back
#define loj(i, j) "Case " << i << ": " << j
#define gap " "

#define auto(x, a) for (auto &x : a)

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n + 2], b[n + 2];

        pair<int, int> p[n + 2], q[n + 2];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            p[i].first = a[i];
            p[i].second = i;
        }

        for (int i = 0; i <n; i++)
        {
            cin >> b[i];
            q[i].first = b[i];
            q[i].second = i;
        }

        sort(p, p + n, [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first > b.first; });
        sort(q, q + n, [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first > b.first; });

        int sum = 0;
        bool f=true;
        for (int i = 0; i < n; i++)
        {
            if(f){
                int x = p[i].first-1-q[p[i].second].first, y = p[q[i].second].first- q[i].first;
                if(x>y) sum+=x;
                else sum-=y;
                
            }else{
                sum-=(q[i].first-1-p[i].first);
            }
        }

        cout << sum << endl;
    }
}