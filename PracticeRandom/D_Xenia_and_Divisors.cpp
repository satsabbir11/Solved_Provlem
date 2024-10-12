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

struct S
{
    int x, y, z;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n;
    cin >> n;

    vector<S> v;

    // 1 2 6

    map<long long, long long> mp;
    for (long long i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;

        mp[x]++;
    }

    if (mp[7] || mp[5])
    {
        cout << -1 << endl;
        return 0;
    }

    if (mp[4])
    {
        if (mp[4] <= mp[2] and mp[4] <= mp[1])
        {
            for (long long i = 1; i <= mp[4]; i++)
            {
                v.push_back({1, 2, 4});
            }
            mp[2] -= mp[4];
            mp[1] -= mp[4];
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }

    if (mp[3])
    {
        if (mp[3] <= mp[6] and mp[3] <= mp[1])
        {
            for (long long i = 1; i <= mp[3]; i++)
            {
                v.push_back({1, 3, 6});
            }
            mp[6] -= mp[3];
            mp[1] -= mp[3];
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }

    if (mp[1] == mp[2] and mp[6] == mp[1])
    {
        for (long long i = 1; i <= mp[6]; i++)
        {
            v.push_back({1, 2, 6});
        }
    }
    else
    {
        cout << -1 << endl;
        return 0;
    }

    for(int i=0; i<v.size(); i++){
        cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].z<<endl;
    }
}