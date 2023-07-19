#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long edges[1009][1009];
long long dist[1009][1009];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dijkstra(long long x, long long y, long long w)
{
    if (dist[x][y] < w)
        return;
    dist[x][y] = w;

    for (int i = 0; i < 4; i++)
    {
        long long new_x = dx[i] + x, new_y = dy[i] + y;

        if (new_x <= n && new_x >= 1 && new_y <= m && new_y >= 1)
        {
            long long new_w = dist[x][y] + edges[new_x][new_y];

            if (new_w < dist[new_x][new_y])
            {
                dist[new_x][new_y] = new_w;
                dijkstra(new_x, new_y, dist[new_x][new_y]);
            }
        }
    }
}

int main()
{
    long long t;
    cin >> t;

    for (long long k = 1; k <= t; k++)
    {

        cin >> n >> m;

        for (long long i = 0; i <= n + 2; i++)
        {
            for (long long j = 0; j <= m + 2; j++)
            {
                // edges[i][j] = 0;
                dist[i][j] = 1e12;
            }
        }

        for (long long i = 1; i <= n; i++)
        {
            for (long long j = 1; j <= m; j++)
                cin >> edges[i][j];
        }

        dijkstra(1, 1, edges[1][1]);

        cout << dist[n][m] << endl;
    }
}