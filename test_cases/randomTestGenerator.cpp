#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));  // Seed with the command line argument for reproducibility

    int t = rand() % 10000 + 1;  // Random number of test cases, 1 <= t <= 10^4
    cout << t << endl;

    int total_n = 0;  // Track the total `n` to avoid exceeding the 2 * 10^5 limit
    for (int test = 0; test < t; ++test) {
        int n = rand() % min(200000 - total_n, 200000) + 1;  // Ensure total n <= 2 * 10^5
        cout << n << endl;

        total_n += n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = rand() % 1000000000 + 1;  // 1 <= a[i] <= 10^9
            cout << a[i] << " ";
        }
        cout << endl;

        if (total_n >= 200000) break;  // Stop if total `n` exceeds 2 * 10^5
    }
    return 0;
}
