#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char in[] = {'R', 'D', 'L', 'U'};

int n, m, ei, ej, si, sj;
bool f = true;
string s;

struct Node{
    int x, y, dist;
    bool operator>(const Node& other) const{
        return dist>other.dist;
    }
};

void dijkstra(vector<vector<bool>>& ed, vector<vector<int>>& dis, vector<vector<char>>& par) {
    priority_queue<Node, vector<Node>, greater<Node>>pq;
    dis[si][sj]=0;
    pq.push({si, sj, 0});

    while(!pq.empty()){
        Node top = pq.top(); pq.pop();
        int x = top.x, y = top.y;

        for(int i=0; i<4; i++){
            int xx = x+dx[i], yy = y + dy[i];
            if(xx<n and xx>=0 and yy<m and yy>=0 and ed[xx][yy]){
                if(dis[xx][yy]>dis[x][y]+1){
                    dis[xx][yy]=dis[x][y]+1;
                    par[xx][yy]=in[i];
                    pq.push({xx, yy, dis[xx][yy]});
                }
            }
        }
    }
    
}

void reconstructPath(vector<vector<char>>& par) {
    int x = ei, y=ej;
    while(x!=si || y!=sj){
        s+=par[x][y];
        if(par[x][y]=='U') x++;
        else if(par[x][y]=='D') x--;
        else if(par[x][y]=='R') y--;
        else y++;
    }
    reverse(all(s));
}

int32_t main() {
    cin >> n >> m;
    vector<vector<bool>> ed(n, vector<bool>(m, false));
    vector<vector<int>> dis(n, vector<int>(m, LLONG_MAX));
    vector<vector<char>> par(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            if (x != '#') ed[i][j] = true;
            if (x == 'A') { si = i; sj = j; }
            if (x == 'B') { ei = i; ej = j; }
        }
    }

    dijkstra(ed, dis, par);

    if (dis[ei][ej] == LLONG_MAX) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << dis[ei][ej] << endl;

    reconstructPath(par);

    cout << s << endl;
}
