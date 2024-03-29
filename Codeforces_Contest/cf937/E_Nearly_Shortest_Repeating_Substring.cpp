#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
#define ull unsigned long long
#define con (f?"YES":"NO")
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define dpos(n) fixed << setprecision(n)

#define clear1(a) memset(a, -1, sizeof(a))
#define clear0(a) memset(a, 0, sizeof(a))

#define sortn(a,x,n) sort(a+x, a+x+n)
#define sortv(s) sort(s.begin(), s.end())
#define reversev(s) reverse(s.begin(), s.end())
#define rsortv(s) sort(s.rbegin(),s.rend())
#define unik(a) unique(a.begin(), a.end()) - a.begin()
#define iotav(s, x) iota(s.begin(), s.end(), x)

#define lowerbound(v,x) lower_bound(v.begin(), v.end(), x)-v.begin()
#define upperbound(v,x) upper_bound(v.begin(), v.end(), x)-v.begin()

#define pb push_back
#define loj(i,j) "Case "<<i<<": "<<j
#define gap " "

#define auto(x,a) for (auto& x : a)
#define print(x) cout << #x << " = " << x << endl

#define moveForward(current, ammount, mod) (amount - current) % mod
#define moveBackward(current, ammount, mod) (((amount - current) % mod) + mod) % mod

long long dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
long long dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, an; cin>>n;
        string s; cin>>s;
        an=n;

        for(int i=1;i<=n;i++){
            if(n%i) continue;
            bool f=false;

            for(int j=0;j<n && j<=i; j+=i){
                int ans = 0;
                for(int k=0;k<n;k++){
                    ans+=(s[j+ k % i]!=s[k]);
                }
                if(ans<=1){
                    f=true;
                    an = i;
                    break;
                }
            }
            if(f) break;
        }
        cout<<an<<endl;
    }
}