#include <bits/stdc++.h>
using namespace std;



int countCommonElements(const std::vector<int> &vec1, const std::vector<int> &vec2)
{
    std::unordered_set<int> elementsSet(vec1.begin(), vec1.end());

    int commonCount = 0;
    for (const int &element : vec2)
    {
        if (elementsSet.find(element) != elementsSet.end())
        {
            ++commonCount;
        }
    }

    return commonCount;
}


void dfs(int u, vector<vector<int>> &p, int x, vector<vector<int>> &pp, vector<bool> &vis)
{
    vis[u] = true;
    for (int v : p[u])
    {
        if (v != x && !vis[v])
        {
            pp[x].push_back(v);
            dfs(v, p, x, pp, vis);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        vector<vector<int>> p(n + 2);
        for (int i = 1; i <= m; i++)
        {
            int xx, yy;
            cin >> xx >> yy;
            if (xx == yy)
                continue;
            p[xx].push_back(yy);
            p[yy].push_back(xx);
        }

        vector<bool> vis(n + 2);

        vector<vector<int>> pp(n + 2);
        dfs(y, p, x, pp, vis);
        vis.assign(n+2, false);
        dfs(x, p, y, pp, vis);

        // for (int xx : pp[x])
        //     cout << xx << endl;
        
        int cm = countCommonElements(pp[x], pp[y]);

        cout<<(-cm+pp[x].size())*(-cm+pp[y].size())<<endl;
    }
}