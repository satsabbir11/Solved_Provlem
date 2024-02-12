#include <bits/stdc++.h>
using namespace std;

void build(long long *tree, long long *lazy, long long *a, long long node, long long l, long long r)
{
    lazy[node] = 0;
    if (l == r)
    {
        tree[node] = a[l];
        return;
    }

    long long left = 2 * node, right = left + 1, mid = l + (r - l) / 2;

    build(tree, lazy, a, left, l, mid);
    build(tree, lazy, a, right, mid + 1, r);
    tree[node] = tree[left] + tree[right];
}

void propagate(long long *tree, long long *lazy, long long node, long long l, long long r)
{
    if (lazy[node])
    {
        tree[node] += (r - l + 1) * lazy[node];
        if (l != r)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

long long query(long long *tree, long long *lazy, long long *a, long long node, long long l, long long r, long long b, long long e)
{
    propagate(tree, lazy, node, l, r);
    if (r < b || e < l)
        return 0;

    if (b <= l && r <= e)
        return tree[node];

    long long mid = l + (r - l) / 2;

    return query(tree, lazy, a, 2 * node, l, mid, b, e) + query(tree, lazy, a, 2 * node + 1, mid + 1, r, b, e);
}

void update_range(long long *tree, long long *lazy, long long *a, long long node, long long l, long long r, long long b, long long e, long long val)
{
    propagate(tree, lazy, node, l, r);
    if (r < b || e < l)
        return;
    if (b <= l && r <= e)
    {
        tree[node] += (r - l + 1) * val;

        if (l != r)
        {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }

    long long mid = l + (r - l) / 2;

    update_range(tree, lazy, a, 2 * node, l, mid, b, e, val);
    update_range(tree, lazy, a, 2 * node + 1, mid + 1, r, b, e, val);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main()
{
    long long t;
    // cin >> t;
    t=1;
    while (t--)
    {
        long long n, q;
        cin >> n >> q;
        long long a[n + 2], tree[4 * n], lazy[4 * n];

        for (long long i = 1; i <= n; i++)
            cin >> a[i];
        build(tree, lazy, a, 1, 1, n);

        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                long long x, y, val;
                cin >> x >> y >> val;
                update_range(tree, lazy, a, 1, 1, n, x, y, val);
                continue;
            }
            long long x;
            cin >> x;
            cout << query(tree, lazy, a, 1, 1, n, x, x) << endl;
        }
    }
}