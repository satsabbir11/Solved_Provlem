#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()

 int32_t main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>v(n), q(n);
        for(int &x: v) cin>>x;

        q=v;

        sort(all(q));

        bool f=true;

        for(int i=0; i<n; i++){
            if(i==n-1){
                if(v[i]!=i+1) f=false;
                break;
            }
            if(v[i]==i+1){}
            else if(abs(v[i]-v[i+1])==1 and v[i]>v[i+1]) swap(v[i], v[i+1]);
            else{
                f=false;
                break;
            }
        }

        cout<<((q!=v or !f) ? "NO": "YES")<<endl;
    }
 }