#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int>a(n+2), val(n+2, 2e5+6), dp(n+2, 0);

        for(int i=1;i<=n;i++) cin>>a[i];

        for(int i=1;i<=n;i++){
            dp[i] = min(dp[i-1]+1, val[a[i]]);
            val[a[i]] = min(val[a[i]], dp[i-1]);
        }

        cout<<n-dp[n]<<endl;
    }
}