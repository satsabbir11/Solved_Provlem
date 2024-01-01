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
        if (n == 1)
        {
            cout << 9 << endl;
            continue;
        }
       

        vector<string> v;
        int cnt = 0;
        for (int i = 0; i < n / 2; i++)
        {
            string s = "1";
            for (int j = 1; j <= i; j++)
                s += '0';
            s += '6';
            for (int j = 1; j <= i; j++)
                s += '0';
            s += '9';
            for (int j = 1; j <= (n - i - i - 3); j++)
                s += '0';
            v.push_back(s);
            cnt++;
        }

        for (int i = 0; i < n / 2; i++)
        {
            string s = "9";
            for (int j = 1; j <= i; j++)
                s += '0';
            s += '6';
            for (int j = 1; j <= i; j++)
                s += '0';
            s += '1';
            for (int j = 1; j <= (n - i - i - 3); j++)
                s += '0';
            v.push_back(s);
            cnt++;
            
        }

        string s = "196";

        for (int j = 1; j <= (n - 3); j++)
            s += '0';
        v.push_back(s);
        

        for (string x : v)
            cout << x << endl;
    }
}