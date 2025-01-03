#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n; cin>>n;
    int a[n+2];

    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    map<int, int>mp;

    int i=1, j=1, cnt=0, ans=0;

    while(i<=n){
        while(j<=i and mp[a[i]]){
            mp[a[j++]]--;
        }
        // cout<<j<<" "<<i<<endl;
        ans=max(ans, i-j+1);
        mp[a[i++]]++;
    }
    cout<<ans<<endl;
}