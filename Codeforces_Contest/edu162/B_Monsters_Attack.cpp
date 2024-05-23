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

long long dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
long long dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, p;
        cin>>n>>p;
        
        pair<long long, long long>a[n+2];
        for(long long i=1;i<=n;i++) cin>>a[i].first;
        for(long long i=1;i<=n;i++){
            cin>>a[i].second;
            a[i].second = abs(a[i].second)*p;
        }

        sort(a+1, a+1+n, [](pair<long long, long long>x, pair<long long, long long>y){
            return x.second<y.second;
        });

        long long sum=0;;
        bool f=true;

        for(long long i=1;i<=n;i++){
          sum+=a[i].first;
          if(sum>a[i].second){
            f=false;
            break;
          }
        }
        cout<<con<<endl;
    }
}