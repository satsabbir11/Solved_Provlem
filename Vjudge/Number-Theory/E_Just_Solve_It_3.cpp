#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n; cin>>n;
    long long ans[n+2]={}, mx = 0;
    map<int, bool>mp;
    for(long long i=1;i<=n;i++){
        long long x; cin>>x;
        
        mp[x]=true;
        mx = max(mx, x);
    }

    ans[1] = n;

    for(long long i=2;i<=mx;i++){
        for(long long j=i;j<=mx;j+=i){
            // cout<<j<<endl;
            if(mp[j]) ans[i]++;
        }
    }

    for(long long i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    
}