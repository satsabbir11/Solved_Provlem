#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n+2];
        for(int i=1;i<=n;i++) cin>>a[i];

        int cur = a[1];
        for(int i=2;i<=n;i++){
            cur = ((cur+a[i])/a[i])*a[i];
        }
        cout<<cur<<endl;
    }
}