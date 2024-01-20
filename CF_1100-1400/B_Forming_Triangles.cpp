#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
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


long long nCr(long long n, long long r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;

    long long res = 1;
    for (long long i = 1; i <= r; i++)
    {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

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

        map<int, int> mp;
        set<int>s;
        for (long long i = 1; i <= n; i++){
            long long x;
            cin >> x;
            mp[x]++;
            s.insert(x);
        }

        long long cnt = 0, ans=0;

        for(auto x: s){
            ans+=nCr(mp[x], 3) + nCr(mp[x], 2) * cnt;
            cnt+=mp[x];
        }

        cout<<ans<<endl;
        
    }
}