const int N = 1e5;
vector<pair<int, int>> adj[N];
int dp[N];
bool visited[N];

void topologicalSort(int v, stack<int>& Stack) {
  visited[v] = true;
  for (auto& neighbor : adj[v]) {
    int next = neighbor.first;
    if (!visited[next]) {
        topologicalSort(next, Stack);
    }
  }
  Stack.push(v);
}
void longestPath(int src, int n) {
  fill(dp, dp + n, INT_MIN);
  dp[src] = 0;
  stack<int> Stack;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
        topologicalSort(i, Stack);
    }
  }
  while (!Stack.empty()) {
    int u = Stack.top();
    Stack.pop();

    if (dp[u] != INT_MIN) {
      for (auto& neighbor : adj[u]) {
        int v = neighbor.first;
        int weight = neighbor.second;
        if (dp[v] < dp[u] + weight) {
          dp[v] = dp[u] + weight;
        }
      }
    }
  }
  //now dp[i] = longest path
  //INT_MIN mane impossible 
}
