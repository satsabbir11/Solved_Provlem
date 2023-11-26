#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

string s;

int traverse(vector<vector<int>> &p, int u, int par, int cnt)
{
   
    cout<<u<<" "<<cnt<<endl;

    if (p[u][0] == 0 && p[u][1] == 0)
        return cnt;

    int x, y;
    x = y = INT_MAX;

    for (int i = 0; i < p[u].size(); i++)
    {
        int v = p[u][i];
        
        if (par != v)
        {
            if (i == 0){
                if (s[v-1]=='L') x = traverse(p, v, u, 0);
                else x = traverse(p, v, u, 1);
            }
            else{
                if (s[v-1]=='R') x = traverse(p, v, u, 0);
                else x = traverse(p, v, u, 1);
            }
        }
    }

    return min(x, y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cin >> s;

        vector<vector<int>> p(n + 5);

        for (int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;

            p[i].push_back(x);
            p[i].push_back(y);
        }

        cout << traverse(p, 1, 0, s[0])<< endl;
    }

    return 0;
}
