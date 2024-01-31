#include <bits/stdc++.h>
using namespace std;

struct Segment
{
    long long sum, suff, pref, ans;
    Segment(long long value = INT_MIN)
    {
        sum = suff = pref = ans = value;
    }
} tree[400005];

Segment combine(Segment l, Segment r)
{
    Segment res;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.sum = l.sum + r.sum;
    res.ans = max({l.ans, r.ans, l.suff + r.pref});
    return res;
}

void update(long long node, long long i, long long j, long long pos, long long val)
{
    if (pos < i or j < pos)
        return;
    if (i == j)
    {
        tree[node] = Segment(val);
        return;
    }

    long long mid = i + (j - i) / 2;
    update(node * 2, i, mid, pos, val);
    update(node * 2 + 1, mid + 1, j, pos, val);

    tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
}

Segment reqSeg(long long node, long long i, long long j, long long l, long long r)
{
    if (j < l or r < i)
        return Segment();
    if (l <= i and j <= r)
        return tree[node];

    long long mid = i + (j - i) / 2;

    return combine(reqSeg(2 * node, i, mid, l, r), reqSeg(2 * node + 1, mid + 1, j, l, r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        update(1, 1, n, i, x);
    }

    long long q;
    cin >> q;
    while (q--)
    {
        long long typo, x, y;
        cin >> typo >> x >> y;
        if (typo)
            cout << reqSeg(1, 1, n, x, y).ans << endl;
        else
            update(1, 1, n, x, y);
    }
}