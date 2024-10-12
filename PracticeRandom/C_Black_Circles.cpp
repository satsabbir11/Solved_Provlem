#include <bits/stdc++.h>
using namespace std;

long long dis(long long x1, long long y1, long long x2, long long y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        pair<long long, long long> a[n + 1];
       
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
        }

        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        bool f = true;

        for (int i = 1; i <= n; i++) {
            if (dis(a[i].first, a[i].second, x2, y2) <= dis(x1, y1, x2, y2)) {
                f = false;
                break;
            }
        }

        cout << (f ? "YES" : "NO") << endl;
    }
}
