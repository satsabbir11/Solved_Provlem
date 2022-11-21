#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")

#define Dpos(n) fixed << setprecision(n)

#define CLR(a) memset(a, -1, sizeof(a))
#define CLN(a) memset(a, 0, sizeof(a))

#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define max5(a,b,c,d,e) max(max4(a,b,c,d),e)
#define min5(a,b,c,d,e) min(min4(a,b,c,d),e)

#define sortn(a,x,y) sort(a+x, a+x+y)
#define sortv(s) sort(s.begin(), s.end())
#define reversev(s) reverse(s.begin(), s.end())
#define reversesortv(s) sortv(s); reversev(s)

#define lowerbound(v,x) lower_bound(v.begin(), v.end(), x)-v.begin()+1
#define upperbound(v,x) upper_bound(v.begin(), v.end(), x)-v.begin()

#define pb push_back
#define loj(i,j) "Case "<<i<<": "<<j
#define gap " "

#define auto(x,a) for (auto& x : a)

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        
        long long a[n+2], k=1, l=n;
        bool f=true;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==0 && f){ k=i; f=false;}
            if(a[i]==1){ l=i;}
        }

        map<long long , long long>mp;
        long long cnt=0, cns=0, ans=0, gns=0;

        for(long long i=n;i>=1;i--){
            if(a[i]==0) cnt++;
            else ans+=cnt;
        }

        cnt=0;

        for(long long i=n;i>=1;i--){
            if(a[i]==0 && i!=k) cnt++;
            else if(a[i]==1 || i==k) cns+=cnt;
        }

        cnt=0;
        a[l]=0;

        for(long long i=n;i>=1;i--){
            if(a[i]==0) cnt++;
            else if(a[i]==1) gns+=cnt;
        }

       cout<<max(gns,max(cns,ans))<<endl;

    }
}