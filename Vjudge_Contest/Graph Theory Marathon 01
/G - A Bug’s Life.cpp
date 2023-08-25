#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>> &p, vector<int> &color) {
    for (int i = 0; i < p[u].size(); i++) {
        int v = p[u][i];
        if (color[v] == -1) {
            color[v] = 1 - color[u];
            if (!dfs(v, p, color)) {
                return false; 
            }
        } else if (color[v] == color[u]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int n, e;
        cin >> n >> e;

        vector<vector<int>> p(n + 1);

        for (int i = 1; i <= e; i++) {
            int x, y;
            cin >> x >> y;
            p[x].push_back(y);
            p[y].push_back(x);
        }

        vector<int> color(n + 1, -1);

        bool f = true;

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!dfs(i, p, color)) {
                    f = false;
                    break;
                }
            }
        }
        cout << "Scenario #" << k << ":" << endl;

        if (f)
            cout << "No suspicious bugs found!" << endl;
        else
            cout << "Suspicious bugs found!" << endl;
    }
}
