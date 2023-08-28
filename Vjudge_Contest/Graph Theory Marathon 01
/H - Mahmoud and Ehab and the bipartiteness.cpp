#include <bits/stdc++.h>
using namespace std;
long long black = 0, white = 0;

void dfs(long long u, long long prev, vector<vector<long long>> &p, bool color)
{
    if(color) black++;
    else white ++;

    for (long long i = 0; i < p[u].size(); i++)
    {
        long long v = p[u][i];
        if (prev != v) dfs(v, u, p, !color);
    }
}

int main()
{
    long long n;
    cin >> n;

    vector<vector<long long>> p(n + 2);
    for (long long i = 1; i <n; i++)
    {
        long long x, y;
        cin >> x >> y;

        p[x].push_back(y);
        p[y].push_back(x);
    }

    dfs(1, 0, p, 0);
    
    cout << white * black - n + 1 << endl;
}