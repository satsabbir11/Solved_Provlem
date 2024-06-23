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

long long gett(char s, char t)
{
    long long x = s - '0', y = t - '0';
    return (x * 10 + y);
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
        string s;
        cin >> s;

        if (n <= 2)
        {
            cout << gett(s[0], s[1]) << endl;
            continue;
        }
         bool f=false;

        for (long long i = 0; i < n; i++)
        {
           
            if (s[i] == '0')
            {
                cout << 0 << endl;
                f=true;
                break;
            }
        }

        if(f) continue;

        long long sum = -1, mn = 105, in;
        vector<long long> v;
        for (long long i = 0; i < n; i++)
        {
            v.push_back(s[i] - '0');

            if (i == n - 1)
                continue;

            long long tem = mn;

            mn = min(mn, gett(s[i], s[i + 1]));

            long long x = gett(s[max(0ll, i - 1)], s[i]);
            long long y = gett(s[i], s[i + 1]);

            if (i > 0 and x == 12 and y == 21)
            {
               mn = x;
               in = i-1;
               continue;
            }

            if (i > 0 and x == 22 and y == 21)
            {
               mn = x;
               in = i;
               continue;
            }

            

            if (tem != mn)
                in = i;
        }

        cout << mn << endl;

        for (long long i = 0; i < n; i++)
            if (i != in and i != in + 1)
            {
                if (sum == -1)
                    sum = v[i];
                else if (v[i] == 1)
                    sum *= v[i];
                else
                    sum += v[i];
            }
        if (sum > 1 and mn > 1)
            sum += mn;
        else
            sum *= mn;

        cout << sum << endl;
    }
}