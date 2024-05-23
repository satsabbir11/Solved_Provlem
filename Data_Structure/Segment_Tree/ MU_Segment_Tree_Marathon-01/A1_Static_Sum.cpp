#include <bits/stdc++.h>
using namespace std;

void build(long long  *tree, long long  *a, long long  node, long long  l, long long  r)
{
    if (l == r)
    {
        tree[node] = a[l];
        return;
    }

    long long  left = 2 * node, right = left + 1;
    long long  mid = (l + r) / 2; // l + (r-l)/2

    build(tree, a, left, l, mid);
    build(tree, a, right, mid + 1, r);

    tree[node] = tree[left] + tree[right];
}

long long  query(long long  *tree, long long  *a, long long  node, long long  l, long long  r, long long  begin, long long  end)
{
    if (r < begin || end < l)
        return 0;

    if (begin <= l && r <= end)
    {
        return tree[node];
    }

    long long  left = 2 * node, right = left + 1;
    long long  mid = (l + r) / 2; // l + (r-l)/2

    long long  left_value = query(tree, a, left, l, mid, begin, end);
    long long  right_value = query(tree, a, right, mid + 1, r, begin, end);

    return left_value + right_value;
}

void update(long long  *tree, long long  *a, long long  node, long long  l, long long  r, long long  index, long long  value)
{
    if (l == r)
    {
        a[l] = value;
        tree[node] = a[l];
        return;
    }

    long long  left = 2 * node, right = left + 1;
    long long  mid = (l + r) / 2;

    if (index <= mid)
        update(tree, a, left, l, mid, index, value);
    else
        update(tree, a, right, mid + 1, r, index, value);

    tree[node] = tree[left] + tree[right];
}

int main()
{
    long long  n;
    cin >> n;
    long long  q;
    cin >> q;

    long long  a[n + 2], tree[4 * n];
    for (long long  i = 1; i <= n; i++)
        cin >> a[i];

    build(tree, a, 1, 1, n);

    while (q--)
    {
        long long  x, y;
        cin>>x>>y;
        long long  desire_value = query(tree, a, 1, 1, n, x, y);
        cout << desire_value << endl;
    }
}