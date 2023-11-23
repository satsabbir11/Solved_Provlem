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
        long long n;
        cin>>n;
        
        long long a[n+n+2], sum=0;
        for(long long i=1;i<=n+n;i++) cin>>a[i];
        sort(a+1, a+1+n+n);

        for(long long i=2;i<=n;i++) sum+=a[i]-a[i-1];
        for(long long i=n+2;i<=n+n;i++) sum+=a[i]-a[i-1];
        cout<<sum<<endl;

        for(long long i=1;i<=n;i++) cout<<a[i]<<" "<<a[n+n-i+1]<<endl;
    }
}