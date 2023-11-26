#include <bits/stdc++.h>
using namespace std;

int di, dj;
int n, m;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int p[1000][1000];
int dis[1000][1000];

void bfs(int ii, int jj) {
    queue<pair<int, int>> q;
    q.push({ii, jj});
    dis[ii][jj] = 0;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int xx = i + dx[k];
            int yy = j + dy[k];

            if (0 > xx || xx >= n || 0 > yy || yy >= m) continue;

            int v = p[xx][yy];

            if (!v && dis[xx][yy] > dis[i][j] + 1) {
                dis[xx][yy] = dis[i][j] + 1;
                if (xx == di && yy == dj) return;
                q.push({xx, yy});
            }
        }
    }
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dis[i][j] = 10000;
                p[i][j] = 0;
            }
        }

        int x;
        cin >> x;
        while (x--) {
            int xx;
            cin >> xx;
            int freq;
            cin >> freq;
            while (freq--) {
                int yy;
                cin >> yy;
                p[xx][yy] = 1;
            }
        }

        int ii, jj;
        cin >> ii >> jj >> di >> dj;
        bfs(ii, jj);

        cout << dis[di][dj] << endl;
    }

    return 0;
}
