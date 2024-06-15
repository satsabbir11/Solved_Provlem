#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin>>n;
        m= n;

        long long mx, mn;
        cin>>mx;
        mn = mx;
        
        for(long long i=2;i<=n;i++){
            long long x;
            cin>>x;
            mn = min(x, mn);
            mx = max(x, mx);
        }
        
        

        if(n==1){
            cout<<0<<endl;
            continue;
        }

        n = mx - mn;
        long long ans = log2(n)+1;
        cout<<ans<<endl;

        if(ans > m) continue;

        while(ans--){
            cout<<n<<" ";
            n/=2;
        }
        cout<<endl;
    }
}