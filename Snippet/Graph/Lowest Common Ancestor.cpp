const int N = 1e5 + 10;
vector<int> adj[N];
int timer, l;
int tin[N], tout[N];
int up[N][18];
int dist[N];
void dfs(int src, int par){
    tin[src] = ++timer;
    up[src][0] = par;
    for (int i = 1; i <= l; ++i)
        up[src][i] = up[up[src][i-1]][i-1];
    for (int child : adj[src]) {
        if(child != par){
            dist[child] = dist[src] + 1;
            dfs(child, src);
        }
    }
    tout[src] = ++timer;
}
bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
void preprocess(int root, int n) {
    timer = 0;
    l = ceil(log2(n));
    dfs(root, root);
}
int getKthAncestor(int node, int k) {
    for(int i = 0; i < 18; i++){
        if(k & (1 << i)){
            node = up[node][i];
            if(node == -1) return -1;
        }
    }
    return node;
}
