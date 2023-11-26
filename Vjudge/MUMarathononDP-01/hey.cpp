#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(a,max3(b,c,d))

int recursion(vector<int>v, vector<int>&dp, int i, int n){
    if(i>n) return 0;
    if(dp[i]!=-1) return dp[i];
    int a = v[i] + recursion(v, dp, i+1, n);
    v[i]*=-1;
    v[i+1]*=-1;
    
    int c = v[i] + recursion(v, dp, i+1, n);
    int b = v[i] + v[i+1]+ recursion(v, dp, i+2, n);
   
    return dp[i] = max3(a,b,c);
}



int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   int n; cin>>n;

   vector<int>a(n+2), dp(n+2,-1);
   for(int i=1;i<=n;i++) cin>>a[i];
   cout<<recursion(a, dp, 1, n)<<endl;
}

