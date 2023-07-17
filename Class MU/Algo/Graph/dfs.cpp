#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> p;
vector<bool> visited;

void dfs(int u)
{
    cout<<u<<" ";

    visited[u] = true;

    for (int v : p[u])
    {
        if (!visited[v])
        {
            visited[v] = true;
            dfs(v);
            
        }
    }
}

void solve()
{
    int nodes, edges;
    cin >> nodes >> edges;

    p.assign(nodes + 2, vector<int>());
    // visited.assign(nodes + 2, false);

    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;

        p[x].push_back(y);
        p[y].push_back(x);
    }

    dfs(1);
}

int main()
{
    solve();
}