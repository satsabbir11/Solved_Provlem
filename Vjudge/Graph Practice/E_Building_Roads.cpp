#include <bits/stdc++.h>
using namespace std;

#define int long long


void dfs(int u, vector<vector<int>>&ed, vector<bool>&vis){
    vis[u]=true;
    for(int v: ed[u]){
        if(vis[v]==false){
            dfs(v, ed, vis);
        }
    }
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m; cin>>n>>m;
    
    vector<vector<int>>ed(n+2);
    vector<int>ans;
    vector<bool>vis(n+2);

    for(int i=1; i<=m; i++){
        int x, y; cin>>x>>y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }



    for(int i=1; i<=n; i++){
        if(vis[i]==false){
            dfs(i, ed, vis);
            ans.push_back(i);
        }
    }

    int l = ans.size();

    cout<<l-1<<endl;
    for(int i=1; i<l; i++){
        cout<<ans[0]<<" "<<ans[i]<<endl;
    }
}
