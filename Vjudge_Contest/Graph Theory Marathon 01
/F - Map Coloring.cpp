#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>> &p, vector<int> &color)
{
    for (int i = 0; i < p[u].size(); i++)
    {
        int v = p[u][i];
        if (color[v] == -1)
        {
            color[v] = 1 - color[u];
            if(!dfs(v, p, color)) return false;
        }
        else if (color[v] == color[u])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> p(105, vector<int>());

    for (int i = 1; i <= n; i++)
    {
       while(1){
        int x;
        cin>>x;
        if(x==0) break;
        p[i].push_back(x);
        p[x].push_back(i);
       }
    }

    vector<int> color(105, -1);
    bool f= true;

    for(int i=1;i<=n;i++){
        if(color[i]!=-1) continue;
        color[i] = 0;
        if(!dfs(i, p, color)){
            f= false;
            break;
        }
    }

    if (f)
    {
       for(int i=1;i<=n;i++) cout<<color[i];
    }
    else
    {
        cout <<-1;
    }
    cout<<endl;
}