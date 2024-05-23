#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        
        long long a[n+2];
        for(long long i=1;i<=n;i++) cin>>a[i];

        for(long long i=1;i<=n;i++) cout<<a[i]<<" ";
    }
}