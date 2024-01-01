#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    vector<long long> dis(n * n, -1LL);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.emplace(0, 0);
    
    while (!q.empty()) {
        auto [d, x] = q.top();
        q.pop();
        
        if (dis[x] != -1) {
            continue;
        }
        dis[x] = d;
        
        int c = x / n, b = x % n;
        if (c == n - 1) {
            cout << d << "\n";
            return;
        }
        q.emplace(d, c * n + c);
        
        for (auto [y, w] : adj[c]) {
            q.emplace(d + s[b] * w, y * n + b);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}