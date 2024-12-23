#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[]={0, 0, 1, 1, 0, 0, -1, -1};
int dy[]={1, 1, 0, 0, -1, -1, 0, 0};

int n, m;

void dfs( vector<vector<bool>>&ed, int x, int y){
    ed[x][y]=false;
    for(int i=0; i<8; i++){
        int xx = x+dx[i], yy = y + dy[i];
        if(xx<n and yy<m and xx>=0 and yy>=0 and ed[xx][yy]) dfs(ed, xx, yy);
    }
}

int32_t main(){
    cin>>n>>m;
    vector<vector<bool>>ed(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char x; cin>>x;
            if(x=='.') ed[i][j]=true;
        }
    }

    int cnt=0;

    for(int i=0 ;i<n; i++){
        for(int j=0; j<m; j++){
            if(ed[i][j]) {cnt++; dfs(ed, i, j);}
        }
    }

    cout<<cnt<<endl;
    
}