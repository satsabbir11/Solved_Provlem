#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> p;
vector<bool> visited;

void bfs(int start)
{
    queue<int> q;

    visited[start] = true;

    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : p[ u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void solve()
{
    int nodes, edges;
    cin >> nodes >> edges;

    p.assign(nodes + 2, vector<int>());
    visited.assign(nodes + 2, false);

    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;

        p[x].push_back(y);
        p[y].push_back(x);
    }

    bfs(1);
}

int main()
{
    solve();
}