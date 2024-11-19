#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()

 int32_t main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>v(n);
        for(int &x: v) cin>>x;

        //sort(all(v));

        int cnt=0, ans=0;

        for(int i=0; i<n-1; i++){
            if(v[i]>v[i+1]){
                ans = max(ans, cnt);
                cnt=0;
            }else cnt++;
        }
        ans = max(cnt, ans);

        cout<<n-1-ans<<endl;
    }
 }