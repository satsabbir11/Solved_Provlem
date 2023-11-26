#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int dfs(int u, vector<vector<int>>&p, vector<int>&conC, int cat[], int m, int prev){
    if(u>1 && p[u].size()==1) return 1;

    int ans = 0;

    for(int i=0;i<p[u].size(); i++){
        int v = p[u][i];
        if(v!=prev){
            if((cat[v]+conC[u])<=m){
                if(cat[v]) conC[v] = cat[v] + conC[u];
                ans += dfs(v, p, conC, cat, m, u);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    int n, m;
    cin>>n>>m;

    int cat[n+2];
    for(int i=1; i<=n;i++) cin>>cat[i];

    vector<vector<int>>p(n+2, vector<int>());

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;

        p[x].push_back(y);
        p[y].push_back(x);
    }

    vector<int>conC(n+1);

    conC[1] = cat[1];

    cout<<dfs(1, p, conC, cat, m, 0)<<endl;
}