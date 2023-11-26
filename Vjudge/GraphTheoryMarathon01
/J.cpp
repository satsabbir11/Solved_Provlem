#include <bits/stdc++.h>
using namespace std;

int N = 20000;

#define loj(i, j) "Case "<<i<<": "<<j

int lk = 0;
int vam = 0;

void dfs(int u, vector<vector<int>>&p, vector<int>&color){
    for(int i=0; i<p[u].size(); i++){
        int v = p[u][i];
        if(color[v]==-1){
            color[v] = 1 - color[u];
            if(color[v]==0) lk++;
            else vam ++;
            dfs(v, p, color);
        }
    }
}

int main(){
    int t;
    cin>>t;
    for(int k=1;k<=t; k++){
        int n;
        cin>>n;

        vector<vector<int>>p(N+2);
        for(int i=1;i<=n;i++){
            int x, y;
            cin>>x>>y;

            p[x].push_back(y);
            p[y].push_back(x);
        }

        vector<int>color(N+2, -1);
        
        int ans = 0;

        for(int i=1;i<=N;i++){
            if(color[i]!=-1 || p[i].empty()) continue;
            lk = 0;
            vam = 0;
            color[i] = 0;
            lk++;
            dfs(i, p, color);
            ans += max(lk, vam);
        }
    
        cout<<loj(k, ans)<<endl;
    }
}