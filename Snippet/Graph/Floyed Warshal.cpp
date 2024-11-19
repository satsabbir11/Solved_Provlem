const int INF = 1e9; // Replace with a suitable large value for infinity

void floydWarshall(vector<vector<int>>& graph, int nodes) {
    for (int k = 1; k <= nodes; k++) {
        for (int i = 1; i <= nodes; i++) {
            for (int j = 1; j <= nodes; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

void addEdge(vector<vector<int>>& dist, int u, int v, int c, int N) {
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            if (dist[x][u] != INF && dist[v][y] != INF) {
                dist[x][y] = min(dist[x][y], dist[x][u] + c + dist[v][y]);
            }
            if (dist[x][v] != INF && dist[u][y] != INF) {
                dist[x][y] = min(dist[x][y], dist[x][v] + c + dist[u][y]);
            }
        }
    }
}

int main() {
    int nodes = 4; // Example: Number of nodes
    vector<vector<int>> graph(nodes + 1, vector<int>(nodes + 1, INF));
    
    // Initialize graph distances
    for (int i = 1; i <= nodes; i++) {
        graph[i][i] = 0; // Distance to self is 0
    }

    // Add some edges (example)
    graph[1][2] = 4;
    graph[2][3] = 5;
    graph[3][4] = 6;

    floydWarshall(graph, nodes);

    int N = nodes; // Example: Graph size for `dist`
    vector<vector<int>> dist = graph; // Copy `graph` to `dist`
    int u = 1, v = 4, c = 3; // Example edge
    addEdge(dist, u, v, c, N);

    // Output the result
    for (int i = 1; i <= nodes; i++) {
        for (int j = 1; j <= nodes; j++) {
            cout << (dist[i][j] == INF ? "INF" : to_string(dist[i][j])) << " ";
        }
        cout << endl;
    }

    return 0;
}