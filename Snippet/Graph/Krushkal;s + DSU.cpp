int par[N];
int sz[N];
void make_set(int v){
    par[v] = v;
}
int find_set(int v){
    if(v == par[v]) return v;
    return par[v] = find_set(par[v]);
}
void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a] > sz[b]) swap(a, b);
        par[a] = b;
        sz[b] += sz[a];
    }
}
void reset(int n){
    for(int i = 0;i <= n;i++){
        make_set(i);
    }
    for(int i = 0;i <= n;i++){
        sz[i] = 0;
    }
}
int mst(vector<pair<int, pair<int, int>>> &edge){
    int ret = 0;
    for(int i = 0;i < edge.size();i++){
        int w = edge[i].first;
        int v1 = edge[i].second.first;
        int v2 = edge[i].second.second;
        if(find_set(v1) == find_set(v2)) continue;
        ret += w;
        union_sets(v1, v2);
    }
    return ret;
}
