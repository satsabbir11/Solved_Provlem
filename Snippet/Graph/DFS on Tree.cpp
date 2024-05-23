vector<vector<int>> p;
vector<long long> depth;
vector<long long> reverse_depth;
void dfs(int u, int par)
{
    if (p[u].size() == 1 && p[u][0] == par){
        depth[u] = depth[par]+1;
        reverse_depth[u] = 1;
    }
    else
    {
        for (auto v : p[u])
        {
            if (v != par)
            {
                depth[v] = 1 + depth[u];
                dfs(v, u);
                reverse_depth[u] = 1 + reverse_depth[v];
            }
        }
    }
}
void solve(int n)
{
    p.assign(n + 2, vector<int>());
    depth.assign(n + 2, 0);
    reverse_depth.assign(n + 2, 0);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p[x].push_back(y);
        p[y].push_back(x);
    }
    depth[1]=1;
    dfs(1, -1);
    int x = 2;
    cout<<depth[x]<<" "<<reverse_depth[x]<<endl;
}