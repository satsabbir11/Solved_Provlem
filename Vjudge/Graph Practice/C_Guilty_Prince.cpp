#include <bits/stdc++.h>
using namespace std;

long long dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
long long dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int n, m, cnt=0;

void dfs(int x, int y, vector<vector<char>>&grid){
    cnt++;
    grid[x][y]='#';
    for(int i=0; i<4; i++){
        int xx = dx[i]+x, yy = dy[i]+y;
        if(xx<n and xx>=0 and yy<m and yy>=0 and grid[xx][yy]=='.'){
            dfs(xx, yy, grid);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
    int t, tt=1;
    cin>>t;
    while(t--){
        cin>>m>>n;
        vector<vector<char>>grid(n, vector<char>(m));
        int x, y;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
                if(grid[i][j]=='@') x=i, y=j;
            }
        }

        cnt=0;
        dfs(x, y, grid);
        cout<<"Case "<<tt++<<": "<<cnt<<endl;
    }
}
