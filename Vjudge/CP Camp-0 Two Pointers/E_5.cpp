#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    multiset<int>w;
    int j = 1, ans = 0;

    for (int i = 1; i <= n; i++) {
        w.insert(a[i]);

        while (*w.rbegin() - *w.begin() > 1) {
            w.erase(w.find(a[j]));
            j++;
        }
        ans = max(ans, i - j + 1);
    }

    cout << ans << endl;
}
