#include <bits/stdc++.h>
using namespace std;

int n, m;
int edges[1009][1009];
int dist[1009][1009];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

typedef pair<int, pair<int, int>> pi;


void dijkstra(int x, int y, int w) {

   priority_queue<pi, vector<pi>, greater<pi>> pq;

    pq.push({w, {x, y}});
    dist[x][y] = w;

    while (!pq.empty()) {
        int curr_w = pq.top().first;
        int curr_x = pq.top().second.first;
        int curr_y = pq.top().second.second;
        pq.pop();

        if (curr_w > dist[curr_x][curr_y])
            continue;

        for (int i = 0; i < 4; i++) {
            int new_x = dx[i] + curr_x;
            int new_y = dy[i] + curr_y;

            if (new_x <= n && new_x >= 1 && new_y <= m && new_y >= 1) {
                int new_w = curr_w + edges[new_x][new_y];

                if (new_w < dist[new_x][new_y]) {
                    dist[new_x][new_y] = new_w;
                    pq.push({new_w, {new_x, new_y}});
                }
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);


    int t;
    cin >> t;

    for (int k = 1; k <= t; k++)
    {

        cin >> n >> m;

        for (int i = 0; i <= n + 2; i++)
        {
            for (int j = 0; j <= m + 2; j++)
            {
                dist[i][j] = 1<<30;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cin >> edges[i][j];
        }

        dijkstra(1, 1, edges[1][1]);

        cout << dist[n][m] << endl;
    }
}

