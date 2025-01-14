#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, k, cnt=0;

void dfs(int u, int catsofar, vector<vector<int>>&ed, vector<int>&cat, int par=-1){
    if(cat[u-1]) catsofar++;
    else catsofar=0;

    if(catsofar>k) return;

    if(u!=1 and ed[u].size()==1){
       // cout<<u<<endl;
        cnt++;
    }

    for(int v: ed[u]){
        if(par!=v) dfs(v, catsofar, ed, cat, u);
    }
}

int32_t main(){
    cin>>n>>k;

    vector<int>cat(n);
    for(int &x: cat) cin>>x;

    vector<vector<int>>ed(n+1);

    for(int i=1; i<n; i++){
        int x, y; cin>>x>>y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }

    dfs(1, 0, ed, cat);
    cout<<cnt<<endl;
}