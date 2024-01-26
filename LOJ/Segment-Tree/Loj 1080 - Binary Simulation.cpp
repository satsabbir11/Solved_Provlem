#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void invert(bool *tree, string &s, long long node, long long l, long long r, long long i, long long j)
{
    if (i == l && j == r)
    {
        tree[node] = !tree[node];
        return;
    }
    long long mid = l + (r - l) / 2;
    long long right = 2 * node + 1, left = 2 * node;

    if (j <= mid)
        invert(tree, s, left, l, mid, i, j);
    else if (i > mid)
        invert(tree, s, right, mid + 1, r, i, j);
    else
    {
        invert(tree, s, left, l, mid, i, mid);
        invert(tree, s, right, mid + 1, r, mid + 1, j);
    }
}

int query(bool *tree, string &s, long long node, long long l, long long r, long long x)
{
    if (l == r)
    {
        return tree[node];
    }


    long long mid = l + (r - l) / 2;
    long long right = 2 * node + 1, left = 2 * node;

    if(tree[node]){
        tree[right] = !tree[right];
        tree[left] = !tree[left];
        tree[node] = false;
    }

    if (x <= mid)
        return query(tree, s, left, l, mid, x);
    else
        return query(tree, s, right, mid + 1, r, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t, k = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long n = s.size();

        bool tree[4 * n + 5] = {0};

        for (long long i = 0; i < n; i++)
        {
            if (s[i] == '1')
                invert(tree, s, 1, 1, n, i+1, i+1);
        }

        cout << "Case " << k++ << ":" << endl;
        long long q;
        cin >> q;
        while (q--)
        {
            char c;
            cin >> c;
            if (c == 'I')
            {
                long long i, j;
                cin >> i >> j;
                invert(tree, s, 1, 1, n, i, j);
            }
            else
            {
                long long x;
                cin >> x;
                cout << query(tree, s, 1, 1, n, x) << endl;
            }
        }
    }
}
