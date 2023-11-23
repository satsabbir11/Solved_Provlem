#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

void dfs(int u, int par, vector<vector<int>> &p, vector<int>&dis)
{
    for (int v : p[u])
    {
        if (par!=v)
        {
            dis[v] = dis[u] + 1;
            dfs(v, u, p, dis);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        vector<int> v(k);
        for (int &x : v)
        {
            cin >> x;
            x--;
        }

        vector<vector<int>> p(n + 2);

        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            p[x].push_back(y);
            p[y].push_back(x);
        }

        if(k==1){
            cout<<0<<endl;
            continue;
        }

        vector<int> dis(n, 0);
        
        dfs(v[0], -1, p, dis);

        int in = v[0];

        for (int i=0;i<k;i++){
            if(dis[in]<dis[v[i]]) in = i;
        }

        dis.assign(n, 0);
        dfs(in, -1, p, dis);
 
       in = v[0];

        for (int i=0;i<n;i++){
            if(dis[in]<dis[v[i]]) in = i;
        }

        cout << (dis[in]+1)/2 << endl;
    }
}