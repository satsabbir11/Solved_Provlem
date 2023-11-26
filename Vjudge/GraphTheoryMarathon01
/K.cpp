#include <bits/stdc++.h>
using namespace std;

int mx = 0, ind;


void dfs(int u, vector<vector<int>>&p, int prev, int dis)
{
    for(int i=0;i<p[u].size();i++){
        int v = p[u][i];
        if(prev!=v){
            if(mx<=(dis+1)){
                mx = dis +1;
                ind = v;
            }
            dfs(v, p, u, dis+1);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>>p(n+2);
    vector<int> dis(n+2);

    for (int i = 1; i <n; i++)
    {
        int x, y;
        cin >> x >> y;

        p[x].push_back(y);
        p[y].push_back(x);
    }

    dis[1] = 0;

    dfs(1, p, 0, 0);
    mx = 0;
    dfs(ind, p, 0, 0);

    cout<<mx<<endl;
}