#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>>&p, vector<int>&color){
    for(int i=0;i<p[u].size(); i++){
        int v = p[u][i];
        if(color[v]==-1){
            color[v] = 1 - color[u];
            dfs(v, p, color);
        }
        else if(color[v]==color[u]) return false;
    }
    return true;
}

 int main(){
    while(1){
        int n,e;
        cin>>n;
        if(n==0) break;
        cin>>e;

        vector<vector<int>>p(n+5, vector<int>());

        for(int i=1; i<=e;i++){
            int x, y;
            cin>>x>>y;

            p[x].push_back(y);
            p[y].push_back(x);
        }

        vector<int>color(n+2, -1);
        color[0] = 0;
        

        if(dfs(0, p, color)){
            cout<<"BICOLORABLE."<<endl;
        }
        else{
           cout<<"NOT BICOLORABLE."<<endl;
        }
    }
 }