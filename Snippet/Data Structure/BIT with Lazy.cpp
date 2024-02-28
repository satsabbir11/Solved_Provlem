#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Fenwick { // 1-indexed
    int n;
    vector<T> t;
    
    Fenwick() {}
    
    Fenwick(int _n) {
        n = _n;
        t.assign(n + 1, 0);
    }
    
    T query(int i) {
        T ans = 0;
        for (; i >= 1; i -= (i & -i))
            ans += t[i];
        return ans;
    }
    
    void upd(int i, T val) {
        if (i <= 0)
            return;
        for (; i <= n; i += (i & -i))
            t[i] += val;
    }
    
    void upd(int l, int r, T val) {
        upd(l, val);
        upd(r + 1, -val);
    }
    
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    long long t;
    // cin >> t;
    t = 1;
    while (t--) {
        long long n, q;
        cin >> n >> q;
        long long a[n + 2];
        Fenwick<long long> tree(n);

        for (long long i = 1; i <= n; i++)
            cin >> a[i];
        
        for (long long i = 1; i <= n; i++)
            tree.upd(i, i, a[i]);

        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                long long x, y, val;
                cin >> x >> y >> val;
                tree.upd(x, y, val);
            } else {
                long long x, y;
                cin >> x;
                cout << tree.query(x) << endl;
            }
        }
    }
    return 0;
}
