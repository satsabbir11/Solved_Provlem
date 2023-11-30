#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    t=1;
    while (t--) {
        long long n, m , ans =0;
        cin>>n>>m;
        
        long long a[n+2];
        for(long long i=1;i<=n;i++) cin>>a[i];

        for(long long i=2;i<=n;i++){
            long long gap = max(0ll, m-a[i]-a[i-1]);
            if(gap){
                a[i]+=gap;
                ans+=gap;
            }
        }
        cout<<ans<<endl;
        for(long long i=1;i<=n;i++) cout<<a[i]<<" ";
    }
}