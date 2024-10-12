#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&vv, vector<bool>&vis, int u, int *cat, int cntC, int m){
    if(cntC>m) return;
    if(!cat[u]) cntC=0;
    //cout<<u<<" "<<cntC<<endl;
    vis[u]=true;
    for(int v: vv[u]) if(!vis[v]){
        dfs(vv, vis, v, cat, cntC+cat[v], m);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    int cat[n + 2];
    for (int i = 1; i <= n; i++)
        cin >> cat[i];

    vector<vector<int>> v(n + 2);
    vector<bool>vis(n+2, false);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    int cnt=0;

    dfs(v, vis, 1, cat, 1, k);

    for (int i = 2; i <= n; i++)
    {
        if(v[i].size()<=1 && vis[i]) cnt++; 
    }
    cout<<cnt<<endl;
}