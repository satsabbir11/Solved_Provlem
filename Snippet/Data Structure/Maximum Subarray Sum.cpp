const ll M = 2e5 + 10;
const ll inf = 1e9 + 10;
ll arr[M];
struct Node
{
    ll sum, pref, suf, ans;
} seg[4 * M];
Node ck(Node l, Node r)
{
    Node res;
    if (l.ans == inf)
        return r;
    if (r.ans == inf)
        return l;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, r.pref + l.sum);
    res.suf = max(r.suf, l.suf + r.sum);
    res.ans = max({l.ans, r.ans, l.suf + r.pref});
    return res;
}
Node make(ll val)
{
    Node tmp;
    tmp.sum = val;
    tmp.pref = tmp.suf = tmp.ans = val;
    return tmp;
}
void build(ll node, ll l, ll r)
{
    if (l == r)
    {
        seg[node] = make(arr[l]);
        return;
    }
    ll mid = (l + r) >> 1;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    seg[node] = ck(seg[node * 2], seg[node * 2 + 1]);
}
void update(ll node, ll l, ll r, ll idx, ll val)
{
    if (l == r)
    {
        seg[node] = make(val);
        return;
    }
    ll mid = (l + r) >> 1;

    if (idx <= mid)
        update(node * 2, l, mid, idx, val);
    else
        update(node * 2 + 1, mid + 1, r, idx, val);

    seg[node] = ck(seg[node * 2], seg[node * 2 + 1]);
}
Node query(ll node, ll l, ll r, ll L, ll R)
{
    if (l > R || r < L)
        return make(inf);
    if (L <= l && R >= r)
        return seg[node];

    ll mid = (l + r) >> 1;
    return ck(query(node * 2, l, mid, L, R), query(node * 2 + 1, mid + 1, r, L, R));
}
int main()
{
    ll n, q;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    cin >> q;
    while (q--)
    {
        ll ty, id, val, i, j;
        cin >> ty;
        if (ty == 0)
        {
            cin >> id >> val;
            update(1, 1, n, id, val);
        }
        else
        {
            cin >> i >> j;
            cout << query(1, 1, n, i, j).ans << endl;
        }
    }
}