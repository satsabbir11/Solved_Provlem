#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Fenwick {
    int n;
    vector<T> t;

    // Default constructor
    Fenwick() {}

    // Constructor with size initialization
    Fenwick(int _n) {
        n = _n;
        t.assign(n + 1, 0);  // 1-indexed, so size is n + 1
    }

    // Point update at index `i` with value `val`
    void upd(int i, T val) {
        if (i <= 0) return;
        for (; i <= n; i += (i & -i))
            t[i] += val;
    }

    // Range update from `l` to `r` with value `val`
    void upd(int l, int r, T val) {
        upd(l, val);
        upd(r + 1, -val);
    }

    // Query the prefix sum up to index `i`
    T query(int i) {
        T sum = 0;
        for (; i >= 1; i -= (i & -i))
            sum += t[i];
        return sum;
    }

    // Query the sum for the range [l, r]
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    // Number of test cases
    long long t = 1;
    while (t--) {
        // Input: number of elements and number of queries
        long long n, q;
        cin >> n >> q;

        // Input array using vector
        vector<long long> a(n + 1);  // 1-indexed

        // Initialize the Fenwick Tree for range updates
        Fenwick<long long> tree(n);

        // Read array values
        for (long long i = 1; i <= n; i++) {
            cin >> a[i];
        }

        // Build the Fenwick tree with initial array values
        for (long long i = 1; i <= n; i++) {
            tree.upd(i, i, a[i]);
        }

        // Process each query
        while (q--) {
            int type;
            cin >> type;

            if (type == 1) {
                // Range update query: increment range [l, r] by `val`
                long long l, r, val;
                cin >> l >> r >> val;
                tree.upd(l, r, val);
            } else {
                // Point query: output the value at index `l`
                long long l;
                cin >> l;
                cout << tree.query(l) << endl;
            }
        }
    }

    return 0;
}

// Example:
// Input:
// 8 3
// 3 2 4 5 1 1 5 3
// 2 4
// 1 2 5 1
// 2 4

// Output:
// 5
// 6