#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j
#define all(s) s.begin(), s.end()

#define bug(a) cout << #a << " : " << a <<endl;

#define int long long

int32_t main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    int t;
    t=1;
    while (t--) {
        int n, k;
        cin>>n>>k;
        
        int a[n+2];
        for(int i=1;i<=n;i++) cin>>a[i];

        int l=0, r=LLONG_MAX, ans=0;

        while(l<=r){
            int sum=0, mid = l+(r-l)/2;
            for(int i=1; i<=n; i++) sum+=mid/a[i];
            if(sum>=k){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans<<endl;
    }
}