#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  int n=4;


  while (t--) {
    long long k;
    cin >> k;

    vector<int>v;

    while (k) {
      int d = k%9;
      if (d >= n) d++;
      v.push_back(d);
      k /= 9;
    }

    reverse(v.begin(), v.end());
    for (int x: v) cout << x;
    cout << endl;
  }
}
