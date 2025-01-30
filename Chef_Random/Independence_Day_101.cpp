#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

int32_t main(){
    int t; cin>>t;
    while(t--){
        int n=3;
        vector<int>v(n);

        for(int &x: v) cin>>x;

        sort(all(v));

        if(v[0]+v[1]-v[2]>=-1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}