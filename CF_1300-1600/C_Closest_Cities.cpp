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

long long dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
long long dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        
        long long a[n+2], b[n+2], cum[n+2]={}, cum1[n+2]={};
        for(long long i=1;i<=n;i++) {cin>>a[i]; b[i]=a[i];}
        reverse(b+1, b+1 + n);

        for(long long i=1;i<=n;i++){
            long long x, y;
            x=y=INT_MAX;
            if(i!=n) x= abs(a[i]-a[i+1]);
            if(i>1) y= abs(a[i]-a[i-1]);
            if(min(x,y)==x) cum[i+1]=cum[i]+1;
            else cum[i+1]=cum[i]+x;
        }

         for(long long i=1;i<=n;i++){
            long long x, y;
            x=y=INT_MAX;
            if(i!=n) x= abs(b[i]-b[i+1]);
            if(i>1) y= abs(b[i]-b[i-1]);
            if(min(x,y)==x) cum1[i+1]=cum1[i]+1;
            else cum1[i+1]=cum1[i]+x;
        }

         //for(long long i=1;i<=n;i++) cout<<cum[i]<<" ";
         cout<<endl;
         long long q;
         cin>>q;
         while(q--){
            int x, y;
            cin>>x>>y;
            if(y>x) cout<<cum[y]-cum[x]<<endl;
            else cout<<cum1[n-y+1]-cum1[n-x+1]<<endl;
         }
    }
}