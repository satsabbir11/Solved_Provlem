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

    long long t, k = 2;
    cin >> t;
    long long nthPrime[10005];
    bool vis[200005];
    nthPrime[1] = 2;
    for (long long i = 3; i <= 200005; i+=2)
    {
        if (!vis[i])
        {
            nthPrime[k++] = i;
            if (k == 10002)
                break;
            for (long long j = i * i; j <= 200005; j += i)
            {
                vis[j] = true;
            }
        }
    }
    //cout<<nthPrime[10000]<<endl;
    while (t--)
    {
        long long n;
        cin >> n;
        if(n%2) cout<<1<<" ";
        for(long long i=1;i<=n/2;i++){
            cout<<nthPrime[i]<<" "<<nthPrime[i]<<" ";
        }
        cout<<endl;
    }
}