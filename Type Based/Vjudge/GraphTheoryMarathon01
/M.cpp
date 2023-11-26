#include <bits/stdc++.h>
using namespace std;
int mx = 0;

void dfs1(int u, int &a, vector<vector<int>>&p, int dis, int prev){
    if(mx<dis){
        mx = dis;
        a = u;
    }
    for(int v: p[u]){
        if(v!=prev) dfs1(v, a, p, dis+1, u);
    }
}

void dfs2(int u, int &a, vector<vector<int>>&p, vector<int>&par , int dis, int prev){
    if(mx<dis){
        mx = dis;
        a = u;
    }
    for(int v: p[u]){
        if(v!=prev){
            par[v] = u;
            dfs2(v, a, p, par, dis+1, u);
        }
    }
}

void dfs3(int u, vector<bool>&vis, vector<vector<int>>&p, int &mxx, int dis, int &a){
    //cout<<u<<" ";
    if(mxx<dis){
        mxx = dis;
        a = u;
    }
    for(int v: p[u]){
        if(vis[v]==false){
            vis[v] =true;
            dfs3(v, vis, p, mxx, dis+1, a);
        }
    }
}

void reset(){
    mx = 0;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>>p(n+2);
    
    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;

        p[x].push_back(y);
        p[y].push_back(x);
    }

    int a, b, firstDistance;
    dfs1(1, a, p, 0, 0);
    reset();
    vector<int>par(n+2);
    par[a] = -1;
    dfs2(a, b, p, par, 0, 0);
    firstDistance = mx;
    reset();
    

    vector<bool>vis(n+2);
    int i = b;
    int c, ans = 0;
    while(i!=-1){
        vis[i] = true;
        if(i!=a && b!=i) c = i;
        i = par[i];
    }

    
    i = b;
    while(i!=-1){
        vis[i] = true;
        int x;
        int mxx = 0;
        //cout<<i<<endl;
        dfs3(i, vis,p, mxx, 0, x);
        //cout<<endl;
        if(ans<mxx){
            ans = mxx;
            c = x;
        }
        i = par[i];
    }
    cout<<firstDistance + ans<<endl;
    cout<<a<<" "<<b<<" "<<c<<endl;
}