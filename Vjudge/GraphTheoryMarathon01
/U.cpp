#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 1, 0, -1, 0, -1};
int dy[] = {1, 0, 1, 0, -1, -1};

int n;
bool f = false;

void dfs(int i, int j, vector<vector<char>>&c, vector<vector<bool>>&vis){
    if(j==(n-1)){
        f= true;
        return;
    }
    for(int k=0;k<6;k++){
        int xx = i+ dx[k], yy = j + dy[k];
        if(xx>=n || yy >=n || xx<0 || yy<0) continue;
        if(c[xx][yy]=='w' && !vis[xx][yy]){
            vis[xx][yy] = true;
            dfs(xx, yy, c, vis);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
    int k = 1;
    while (1)
    {
        cin >> n;
        if (!n)
            break;

        vector<vector<char>>c(n+2, vector<char>(n+2));

        for(int i=0;i<n;i++){
            for(int j = 0; j<n; j++){
                cin>>c[i][j];
            }
        }

        vector<vector<bool>>vis(n+2, vector<bool>(n+2));

        f = false;

        for(int i=0; i<n; i++){
            if(!vis[i][0] && c[i][0]=='w'){
                vis[i][0] = true;
                dfs(i, 0, c, vis);
            }
        }


        cout<<k++<<" ";

        if(f) cout<<'W'<<endl;
        else cout<<'B'<<endl;
    }
}
