#include <bits/stdc++.h>
using namespace std;
#define loj(i,j) "Case "<<i<<": "<<j


int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int dfs(int n, int m, int ii, int jj, vector<vector<char>> &s, vector<vector<bool>>&vis)
{
    int ans =0;
    
    for(int i=0;i<4;i++){
        int ix = ii+ dx[i];
        int iy = jj + dy[i];

        if(ix == -1 || ix == n || iy == -1 || iy == m) continue;

        if(!vis[ix][iy] && s[ix][iy]=='.'){
            vis[ix][iy] = true;
            ans += 1 + dfs(n, m, ix, iy, s, vis);
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    for(int kk =1; kk<=t; kk++)
    {
        int n, m, in, jn;
        cin >> m >> n;

        vector<vector<char>>s(n, vector<char>(m));
        vector<vector<bool>>vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>s[i][j];
                if(s[i][j]=='@'){
                    in = i;
                    jn = j;
                }
            }
        }

        vis[in][jn] = true;

        cout<<loj(kk,dfs(n, m, in, jn, s, vis)+1)<<endl;
    }
}