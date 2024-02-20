#include <bits/stdc++.h>
using namespace std;

int Bit(int n){
    return n^((1<<31)-1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int>s;
        map<int, int>mp;

        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            s.insert(x);
            mp[x]++;
        }

        int ans = 0;

        for(auto x:s){
            int y= Bit(x);
            ans+=min(mp[x], mp[y])+abs(mp[x]-mp[y]);
            mp[x]=0;
            mp[y]=0;
        }

        cout<<ans<<endl;
    }
}