#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

const int MAXN = 100005; // Update the maximum size

int rk[MAXN], par[MAXN];

int find(int a)
{
    if (par[a] == a)
        return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (rk[a] < rk[b])
        swap(a, b);
    par[b] = a;
    rk[a] += rk[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t, k = 1;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            par[i] = x;
        }

        for (int i = 0; i <= n; i++) // Update the loop condition
        {
            rk[i] = 0;
        }

        cout << "Case " << k++ << ": " << endl;

        while (m--)
        {
            int tt;
            cin >> tt;
            if (tt == 1)
            {
                int x, y;
                cin >> x >> y;
                par[x] = y;
            }
            else
            {
                int x;
                cin >> x;
                cout << find(x) << endl;
            }
        }
    }
}
