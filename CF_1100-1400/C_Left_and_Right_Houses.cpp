#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int ans = -1;
        int pre[n+2]={};
        for(int i=1;i<=n;i++){
            pre[i] = pre[i-1] + s[i-1]-'0'; 
        }

        for(int i=0;i<=n;i++){
            int left = i-pre[i], right = pre[n]-pre[i];
            if(left*2>=i and right*2>=n-i){
                if(ans==-1 or abs(n - 2*i)<abs(n - 2*ans)) ans = i;
            }
        }
        cout<<ans<<endl;
    }
}