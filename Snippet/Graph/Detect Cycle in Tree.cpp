void dfs(int u, vector<bool> &vis, vector<vector<int>>&p, int prev)
{
    if(vis[u]){
        cycle = true;
        return;
    }

    vis[u] = true;

    for (int i = 0; i < p[u].size(); i++)
    {
        int v = p[u][i];
        if(prev!=v){
            dfs(v, vis, p, u);
        }
    }
}