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

        pair<int, int> a[n + 2];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sortn(a, 1, n);

        int cur = 1;
        vector<int> v(n+2);
        map<int, bool>mp;
        int g=1;
        bool f=false;

        for (int i = 1; i <= n; i++)
        {
            if(f) g=2;
            v[a[i].second] = cur;
            if (a[i].first == a[i + 1].first && !mp[a[i].first]){
                cur+=g;
                mp[a[i].first]=true;
                f=true;
            }
            else
                cur = 1;
        }

        map<int, bool>mp1;


         for (int i = 1; i <= n; i++){
            mp1[v[i]]=true;
         }

        long long fnt=0;
        for(int i=1;i<=3;i++){
            if(mp1[i]) fnt++;
        }

        if(fnt!=3){
            cout<<-1<<endl;
            continue;
        }

        for (int i = 1; i <= n; i++) cout<<v[i]<<" ";
        cout<<endl;
    }
}