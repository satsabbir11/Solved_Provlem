#include <bits/stdc++.h>
using namespace std;


int update(int *tree, int *a, int node, int l, int r, int i=0)
{
    if (i && (r < i || l > i))
        return tree[node];

    if (l==r) return tree[node] = a[l];
       
    int left = 2 * node;
    int right = left + 1;

    int mid = l + (r - l) / 2;

    return tree[node] = update(tree, a, left, l, mid, i) + update(tree, a, right, mid + 1, r, i);
}

int getS(int *tree, int *a, int node, int l, int r, int rl, int rr)
{
    if (rr < l || rl > r)
        return 0;

   if (rl <= l && r<=rr)
        return tree[node];

    int left = 2 * node;
    int right = left + 1;

    int mid = l + (r - l) / 2;

    return getS(tree, a, left, l, mid, rl, rr) + getS(tree, a, right, mid + 1, r, rl, rr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t, ii = 1;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        int a[n + 2], tree[4 * n + 10];
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        update(tree, a, 1, 1, n);

        cout << "Case " << ii++ << ": " << endl;

        while (q--)
        {
            int ty;
            cin >> ty;
            if (ty == 1)
            {
                int x;
                cin >> x;
                cout << a[x + 1] << endl;
                a[x + 1] = 0;
                update(tree, a, 1, 1, n, x + 1);
            }
            else if (ty == 3)
            {
                int x, y;
                cin >> x >> y;
                cout << getS(tree, a, 1, 1, n, x + 1, y + 1) << endl;
            }
            else
            {
                int x, y;
                cin >> x >> y;
                a[x + 1] += y;
                update(tree, a, 1, 1, n, x + 1);
            }
        }
    }
}