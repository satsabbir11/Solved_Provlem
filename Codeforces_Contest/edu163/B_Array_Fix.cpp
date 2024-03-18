#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
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
#define print(x) cout << #x << " = " << x << endl

#define moveForward(current, ammount, mod) (amount - current) % mod
#define moveBackward(current, ammount, mod) (((amount - current) % mod) + mod) % mod

long long dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
long long dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool isSplitable(int n){
    string s = to_string(n);
    for(int i=1;i<s.size();i++) if(s[i-1]>s[i]) return false;
    return true;
}

int firstInt(int n){
    int ans;
    while(n){
        ans=n%10;
        n/=10;
    }
    return ans;
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

        bool f = true;

        int a[n + 2], cur=0;
        bool vis[n+2]={};
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        

        for(int i=1;i<=n;i++){
            if(cur>a[i]){
                f=false;
                break;
            }
            if(firstInt(a[i])>=cur) vis[i]=true;
            if(vis[i]) vis[i] = isSplitable(a[i]);
            if(vis[i]) cur = a[i]%10;
            else cur = a[i];
            //cout<<cur<<endl;
        }

        cout << con << endl;
    }
}