template <class T>
struct SegmentTree
{
    vector<T> tree, lazy, a;
    int n;

    SegmentTree(int size)
    {
        n = size;
        tree.resize(4 * n);
        lazy.resize(4 * n);
        a.resize(n + 1);
    }

    void build_tree(int node, int l, int r)
    {
        lazy[node] = 0;
        if (l == r)
        {
            tree[node] = a[l];
            return;
        }
        int left = 2 * node, right = left + 1, mid = l + (r - l) / 2;
        build_tree(left, l, mid);
        build_tree(right, mid + 1, r);
        tree[node] = tree[left] + tree[right];
    }

    void propagate(int node, int l, int r)
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

    T query(int node, int l, int r, int b, int e)
    {
        propagate(node, l, r);
        if (r < b || e < l)
            return 0;
        if (b <= l && r <= e)
            return tree[node];
        int mid = l + (r - l) / 2;
        return query(2 * node, l, mid, b, e) + query(2 * node + 1, mid + 1, r, b, e);
    }

    void update(int node, int l, int r, int b, int e, T val)
    {
        propagate(node, l, r);
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
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, b, e, val);
        update(2 * node + 1, mid + 1, r, b, e, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update_range(int l, int r, T val)
    {
        update(1, 1, n, l, r, val);
    }

    T range_query(int l)
    {
        return query(1, 1, n, l, l);
    }

    T range_query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }

    void set_array(const vector<T>& input)
    {
        for (int i = 1; i <= n; i++)
            a[i] = input[i - 1];
        build_tree(1, 1, n);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    SegmentTree<long long> st(n);
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    st.set_array(arr);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            long long val;
            cin >> l >> r >> val;
            st.update_range(l, r, val);
        }
        else
        {
            int l;
            cin >> l;
            cout << st.range_query(l) << endl;
        }
    }
}