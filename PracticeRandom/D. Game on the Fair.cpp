#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, k=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int a[n+2], m=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            m= max(m, a[i]);
        }

        int dp[n+m+10]={};
        int mx = a[1];
        for(int i=1;i<=mx;i++){
            if(i+a[i]>mx){
                mx = i+a[i];
                for(int j=mx;j>i;j--){
                    if(dp[j]) break;
                    dp[j] = dp[i]+1;
                }
                if(mx>=n) break;
            }
        }
        cout<<"Case "<<k++<<": "<<dp[n]<<endl;
    }
}