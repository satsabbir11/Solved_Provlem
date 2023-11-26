#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "Yes" : "No")
#define loj(i, j) "Case " << i << ": " << j

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool placeShip(vector<vector<char>> &v, int n, int m, int i, int j, char c)
{
    for (int ii = 0; ii < 4; ii++)
    {
        int ni = i + dx[ii];
        int nj = j + dy[ii];
        
        if (ni >= 0 && ni < n && nj >= 0 && nj < m)
        {
            char pos = v[ni][nj];
            if (pos == '.')
            {
                v[ni][nj] = 'D';
            }
            else if (pos == 'W')
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }

    bool f = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x = v[i][j];
            if(x=='S') f &= placeShip(v, n, m, i, j, x);
        }
    }

    cout << con << endl;
    if (f)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << v[i][j];
            cout << endl;
        }
    }

    return 0;
}
