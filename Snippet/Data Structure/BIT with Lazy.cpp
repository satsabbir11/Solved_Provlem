template <class T>
struct Fenwick {
    int n;
    vector<T> t;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        t.assign(n + 1, 0);  // 1-indexed, so size is n + 1
    }
    void upd(int i, T val) {
        if (i <= 0) return;
        for (; i <= n; i += (i & -i))
            t[i] += val;
    }
    void upd(int l, int r, T val) {
        upd(l, val);
        upd(r + 1, -val);
    }
    T query(int i) {
        T sum = 0;
        for (; i >= 1; i -= (i & -i))
            sum += t[i];
        return sum;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    long long t = 1;
    while (t--) {
        long long n, q;
        cin >> n >> q;
        vector<long long> a(n + 1);  // 1-indexed
        Fenwick<long long> tree(n);
        for (long long i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (long long i = 1; i <= n; i++) {
            tree.upd(i, i, a[i]);
        }
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                long long l, r, val;
                cin >> l >> r >> val;
                tree.upd(l, r, val);
            } else {
                long long l;
                cin >> l;
                cout << tree.query(l) << endl;
            }
        }
    }
}