#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j
#define MOD 100000007

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t, tt=0;
    cin >> t;
    while (t--) {
        long long n, k;
        cin>>n>>k;
        
        vector<int>v(n);
        for(int &x: v) cin>>x;

        vector<vector<int>>dp(n+5, vector<int>(k+5));

        for(int i=1;i<=n;i++){
            dp[i-1][0] = 1;
            for(int j=0;j<=k;j++){
                int ans = dp[i-1][j];
                if(j-v[i-1]>=0) ans+=dp[i][j-v[i-1]];
                ans%=MOD;
                dp[i][j] = ans;
            }
        }
        cout<<loj(++tt, dp[n][k])<<endl;
    }
}