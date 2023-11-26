#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>&p, int prev, vector<int>&dis){
    for(int i=0;i<p[u].size(); i++){
        int v = p[u][i];
        if(prev!=v){
            dis[v] = dis[u] + 1;
            dfs(v, p, u, dis);
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;

        vector<vector<int>>p(n+5);
        vector<int>dis(n+5, -1);

        for(int i=1;i<=m;i++){
            int x, y;
            cin>>x>>y;

            p[x].push_back(y);
            p[y].push_back(x);
        }

        int s;
        cin>>s;
        dis[s] = 0;
        
        queue<int>q;
        q.push(s);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int i=0;i<p[u].size(); i++){
                int v = p[u][i];
                if(dis[v]==-1){
                    q.push(v);
                    dis[v] = dis[u] +1;
                }
            }
        }

        for(int i=1;i<=n;i++){
            if(i==s) continue;
            if(dis[i]!=-1) cout<<dis[i]*6<<" ";
            else cout<<-1<<" ";
        }
        cout<<endl;
    }
}