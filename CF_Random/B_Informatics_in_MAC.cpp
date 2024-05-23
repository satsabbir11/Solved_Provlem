#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; int a[n+2];
        map<int, int>mp, dp;
        for(int i=1;i<=n;i++) {cin>>a[i]; mp[a[i]]++;}

        dp=mp;

        int mex = 0, i;
        bool vis[n+2]={}, f=true;
        for(i=1;i<=n;i++){
            vis[a[i]]=true;
            while(vis[mex]) mex++;
            if(mp[a[i]]>=2 and mp[mex]==0) break;
            mp[a[i]]--;
        }

        int mex2=0;
        bool dis[n+2]={};

        int ii =i;

        mp.clear();

        for(i=i+1;i<=n;i++){
            dis[a[i]]=true;
            while(dis[mex2]) mex2++;
            if(dp[a[i]]>=2 and dp[mex2]==0) break;
            dp[a[i]]--;
        }

        i=ii;

        if(i>=n or mex!=mex2) cout<<-1<<endl;
        else{
            cout<<2<<endl<<1<<" "<<i<<endl<<i+1<<" "<<n<<endl;
        }
    }
}