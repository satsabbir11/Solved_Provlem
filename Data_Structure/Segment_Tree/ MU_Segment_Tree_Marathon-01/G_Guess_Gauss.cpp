#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

template <class T>
struct BIT { //1-indexed
  int n; vector<T> t;
  BIT() {}
  BIT(int _n) {
    n = _n; t.assign(n + 1, 0);
  }
  T query(int i) {
    T ans = 0;
    for (; i >= 1; i -= (i & -i)) ans += t[i];
    return ans;
  }
  void upd(int i, T val) {
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) t[i] += val;
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
    BIT<long long> bit(10); // Creating a BIT object for an array of size 10
    
    // Updating elements
    bit.upd(1, 5);  // Add 5 to the 1st element
    bit.upd(3, 7);  // Add 7 to the 3rd element
    bit.upd(2, 4, 3); // Add 3 to elements from index 2 to 4 (inclusive)
    
    // Querying elements
    cout << bit.query(1, 3) << endl; // Query sum of elements from index 1 to 3
    cout << bit.query(1, 4) << endl; // Query sum of elements from index 1 to 5
    
    return 0;
}
