#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int x, n, ans =1; cin>>x>>n;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                if(n<=x/i) ans = max(i, ans);
                if(n<=i) ans = max(x/i, ans);
            }
        }
        cout<<ans<<endl;
    }
}