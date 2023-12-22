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

#define CLR1(a) memset(a, -1, sizeof(a))
#define CLR0(a) memset(a, 0, sizeof(a))

#define sortn(a,x,n) sort(a+x, a+x+n)
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


long long dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
long long dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, k, sum=0, mx = 0, m=0;
        cin>>n>>k;

        vector<pair<long long, long long>>p(n);
    
        for(long long i=0;i<n;i++) cin>>p[i].first;
        for(long long i=0;i<n;i++) cin>>p[i].second;

         for(long long i=0;i<n;i++){
            long long x = p[i].first, y = p[i].second;
            sum+=x;
            k--;
            long long avl = max(0ll, k);
            m = max(m, y);
            mx = max(mx, sum + avl * m);

            if(k==0) break;
         }

         mx = max(mx, sum + k * m);

         cout<<mx<<endl;
    }
}