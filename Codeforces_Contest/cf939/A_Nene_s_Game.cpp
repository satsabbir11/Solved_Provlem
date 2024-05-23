#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        vector<int>a(n+2);
        for(int i=1;i<=n;i++) cin>>a[i];
        while(k--){
            int q; cin>>q;
            cout<<min(q, a[1]-1)<<" ";
        }
        cout<<endl;
    }
}