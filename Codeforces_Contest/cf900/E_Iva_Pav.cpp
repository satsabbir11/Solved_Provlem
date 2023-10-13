#include <bits/stdc++.h>
#define MAX 200005
#define bitscount 32
using namespace std;

long long prefix_count[bitscount][MAX];

void findPrefixCount(long long arr[], long long n) {
    for (long long i = 0; i < bitscount; i++) {
        prefix_count[i][0] = 0; 
        for (long long j = 1; j <= n; j++) {
            prefix_count[i][j] = prefix_count[i][j - 1] + ((arr[j] >> i) & 1);
        }
    }
}

long long rangeAnd(long long l, long long r, long long n) {
    long long ans = (1LL << bitscount) - 1; 
    for (long long i = 0; i < bitscount; i++) {
        long long x;
        if (l == 1) 
            x = prefix_count[i][r];
        else
            x = prefix_count[i][r] - prefix_count[i][l - 1];
        if (x < r - l + 1)
            ans &= ~(1LL << i); 
    }
    return ans;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long a[n + 1];
        for (long long i = 1; i <= n; i++) cin >> a[i];

        findPrefixCount(a, n);

        long long q;
        cin >> q;

        while (q--) {
            long long x, y;
            cin >> x >> y;

            long long left = x, right = n, result = -1;
            while (left <= right) {
                long long mid = (left + right) / 2;
                if (rangeAnd(x, mid, n) >= y) {
                    result = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            cout << result << " ";
        }
        cout << endl;
    }
    return 0;
}
