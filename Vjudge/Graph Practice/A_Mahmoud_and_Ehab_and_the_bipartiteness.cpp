#include <bits/stdc++.h>
using namespace std;

#define int long long

int green, red;

void dfs(int u, vector<vector<int>>&ed, vector<int>&color){
    for(int v: ed[u]){
        if(color[v]==-1){
            color[v] = 1- color[u];
            if(color[v]==0) green++;
            else red++;
            dfs(v, ed, color);
        }
    }
}

int32_t main(){
    int n; cin>>n;

    green=red=0;

    vector<vector<int>>ed(n+2);
    vector<int>color(n+2, -1);

    for(int i=1; i<n; i++){
        int x, y; cin>>x>>y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        if(color[i]==-1){
            color[i]=0;
            green++;
            dfs(i, ed, color);
        }
    }

    green--, red--;
    cout<<max(0ll, green*red)<<endl;
}