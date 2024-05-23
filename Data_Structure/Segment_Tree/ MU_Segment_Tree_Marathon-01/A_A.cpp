#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define print(x) cout << #x << " = " << x << endl

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   string s, t;
   cin>>s>>t;
   long long n = s.size(), m = t.size(), res=0, fe=-1, se;

   long long dp[n+2][m+2]={};

   for(long long i=1;i<=n;i++){
    for(long long j=1; j<=m;j++){
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        if(s[i-1]==t[j-1]){
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
        res = max(res, dp[i][j]);
    }
   }
   cout<<res<<endl;
}
