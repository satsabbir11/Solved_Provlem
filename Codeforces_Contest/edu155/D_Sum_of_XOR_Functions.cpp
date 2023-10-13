#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long result = 0;
    int prefix_xor = 0;
    int suffix_xor = 0;

    for (int i = 0; i < n; ++i) {
        prefix_xor ^= a[i];
        suffix_xor ^= a[n - i - 1];
        result = (result + 1LL * (i + 1) * (n - i) % MOD * prefix_xor % MOD * suffix_xor) % MOD;
    }

    std::cout << result << std::endl;

    return 0;
}
