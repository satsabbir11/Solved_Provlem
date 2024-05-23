void topologicalSortUtil(
    int v,
    vector<vector<int>> &adj,
    vector<bool> &visited,
    stack<int> &Stack)
{
    visited[v] = true;
    for (int i : adj[v])
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }
    Stack.push(v);
}

void topologicalSort(vector<vector<int>> &adj, int N)
{
    stack<int> Stack;
    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }
    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
