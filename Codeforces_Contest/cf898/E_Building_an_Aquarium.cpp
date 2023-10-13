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
        long long n, k;
        cin>>n>>k;
        
        long long a[n+2];
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }

        sort(a+1, a+1+n);

        long long l =1, r =1e12;

        while(l<=r){
            long long mid = l+(r-l)/2, wt =0;

            for(long long i=1;i<=n;i++){
                if(mid>=a[i]) wt+=(mid-a[i]);
            }
            if(wt>k) r= mid-1;
            else l = mid+1;
        }
        cout<<l-1<<endl;
    }
}