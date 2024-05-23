#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
#define endl "\n"
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

    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin>>n>>k;
        
        long long a[n+n+2];
        map<long long, long long>mp1, mp2;
        for(long long i=1;i<=n+n;i++){
            cin>>a[i];
            if(i<=n) mp1[a[i]]++;
            else mp2[a[i]]++;
        }

        long long kk = 2*k, kk1=0;
        vector<long long>v;

        for(long long i=1;i<=n;i++){
            if(mp1[a[i]]==2 and kk>=2){
                cout<<a[i]<<" "<<a[i]<<" ";
                mp1[a[i]]-=2;
                kk-=2;
                kk1+=2;
            }
        }

        for(long long i=n+1; i<=n+n;i++){
            if(mp2[a[i]]==2 and kk1){
                v.push_back(a[i]);
                v.push_back(a[i]);
                mp2[a[i]]-=2;
                kk1-=2;
            }
        }

        kk1=0;

        for(long long i=1;i<=n;i++){
            if(mp1[a[i]]==1 and kk>=1){
                cout<<a[i]<<" ";
                kk--;
                v.push_back(a[i]); 
            }
        }

        cout<<endl;

        for(long long x: v) cout<<x<<" ";
        cout<<endl;

    }
}