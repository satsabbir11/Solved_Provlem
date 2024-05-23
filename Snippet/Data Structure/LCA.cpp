const int N = 1e5 + 10;
int tin[N], tout[N];
int up[N][32];
vector<int> adj[N];
int n, lg, timer;
void dfs(int src, int par)
{
    tin[src] = ++timer;
    up[src][0] = par;
    for(int i = 1; i <= lg; i++)
    {
        up[src][i] = up[up[src][i - 1]][i - 1];
    }
    for(auto child : adj[src])
    {
        if(child != par)
            dfs(child, src);
    }
    tout[src] = ++timer;
}
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v)
{
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;
    for(int i = lg; i >= 0; i--)
    {
        if(!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
void pre_process(int root)
{
    timer = 0;
    lg = ceil(log2(n));
    dfs(root, root);
}