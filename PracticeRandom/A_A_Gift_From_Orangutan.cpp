#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n+2]; for(int i=1; i<=n;i++) cin>>a[i];
        sort(a+1, a+1+n);

        cout<<(n-1)*(a[n]-a[1])<<endl;
    }
}