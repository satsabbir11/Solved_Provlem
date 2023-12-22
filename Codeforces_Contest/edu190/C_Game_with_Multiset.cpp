#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;

    vector<bool> dp(1 << 20, false);
    dp[0] = true;

    while (m--) {
        int t, v;
        cin >> t >> v;

        if (t == 1) {
            // ADD query
            for (int mask = (1 << 20) - 1; mask >= 0; --mask) {
                if (dp[mask]) {
                    dp[mask | (1 << v)] = true; // Add an element equal to 2^v to the multiset
                }
            }
        } else {
            // GET query
            cout << (dp[v] ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
