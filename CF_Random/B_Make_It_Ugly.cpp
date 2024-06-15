#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; int a[n+5];
        int ans = n;
        for(int i=0;i<n;i++) cin>>a[i];
        int last = -1;
        for(int i=0;i<n;i++){
            if(a[0]!=a[i]){
                ans = min(ans, i-last-1);
                last = i;
            }
        }

       ans = min(ans, n-last-1);

        if(ans==n) ans=-1;
        cout<<ans<<endl;
    }
}