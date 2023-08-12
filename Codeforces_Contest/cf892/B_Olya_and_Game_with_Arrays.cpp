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
#define unik(a) unique(a.begin(), a.end()) - a.begin()

#define lowerbound(v,x) lower_bound(v.begin(), v.end(), x)-v.begin()
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
        
        long long a[n+2][2];
        for(long long i=1;i<=n;i++){
            a[i][0]=1e12;
            a[i][1] =1e12;
        }
        for(long long i=1;i<=n;i++){
            long long m;
            cin>>m;

            if(m==2){
                long long b[2];
                cin>>b[0]>>b[1];
                a[i][1]=max(b[0], b[1]);
                a[i][0]=min(b[0], b[1]);
                continue;
            }
            
            for(long long j=1;j<=m; j++){
                long long x;
                cin>>x;
                if(a[i][1]>x){
                    long long tem = a[i][1];
                    a[i][1] = x;
                    a[i][0] = tem;
                }
                else{
                    if(x>=a[i][1] && a[i][0]>=x) a[i][0] = x;
                }
                
            }
            swap(a[i][0], a[i][1]);
        }

        long long ans =0;
        long long mn = 1e12;

        for(long long i=1;i<=n;i++){
            ans+=a[i][1];
            mn = min(a[i][1], mn);
        }
        ans-=mn;
        mn = 1e12;
        for(long long i=1;i<=n;i++){
            mn = min(a[i][0], mn);
        }
        ans+=mn;
        cout<<ans<<endl;
    }
}