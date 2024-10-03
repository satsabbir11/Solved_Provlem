#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n, d, k; cin>>n>>d>>k;
        vector<int>a(n+2);
        for(int i=0;i<k;i++){
            int x, y; cin>>x>>y;
            a[x]++;
            a[y+1]--;
        }

        for(int i=2; i<=n; i++){
            a[i]+=a[i-1];
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}