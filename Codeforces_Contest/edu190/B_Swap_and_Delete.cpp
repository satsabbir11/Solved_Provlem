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
#define reversesortv(s) \
    sortv(s);           \
    reversev(s)
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
        string s;
        cin >> s;
        int n = s.size(), cnt0 = 0, cnt1 = 0;
        for (char x : s)
        {
            if (x != '1')
                cnt0++;
            else
                cnt1++;
        }

        int fnt = 1;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i + 1])
                fnt++;
        }
        bool f=true;

        if (cnt0 == cnt1)
            cout << 0 << endl;
        else
        {
            for (char x : s)
            {

               // cout<<cnt0<<" "<<cnt1<<endl;
                if(cnt0<0 || cnt1<0){
                    cout<<max(cnt1, cnt0)<<endl;
                    f=false;
                    break;
                }
                if (x== '0')
                    cnt1--;
                else
                    cnt0--;
            }
            if(f) cout<<max(cnt0, cnt1)<<endl;
        }
    }
}