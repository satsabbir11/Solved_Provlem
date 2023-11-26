#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t=1;
    while (t--) {
        long long n, sum=0, mn=1e9+5, neg =0;
        cin>>n;

        
        for(long long i=1;i<=n;i++){
           long long x;
           cin>>x;
           if(x<0) neg++;
           sum+=abs(x);
           mn = min(mn, abs(x));
        }

        if(neg&1) cout<<sum-2*mn<<endl;
        else cout<<sum<<endl;
    }
}