#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    for (int len = 1; len <= n; len++) {
        if (n % len != 0) {
            continue;
        }
        
        for (int i = 0; i < n && i <= len; i += len) {
            std::cout<<i<<" "<<len<<std::endl;
            int ans = 0;
            for (int j = 0; j < n; j++) {
                ans += (s[i + j % len] != s[j]);
            }
            if (ans <= 1) {
                std::cout << len << "\n";
                return;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}