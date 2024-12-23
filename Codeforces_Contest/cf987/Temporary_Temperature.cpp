#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(s) s.begin(), s.end()

const long long N = 2e5 + 5, K = 18; // K = log2(N)
long long a[N], sparseMin[N][K], sparseMax[N][K];

void build(long long n) {
    for (long long i = 1; i <= n; i++) {
        sparseMin[i][0] = a[i]; // Initialize minimum sparse table
        sparseMax[i][0] = a[i]; // Initialize maximum sparse table
    }

    for (long long j = 1; (1 << j) <= n; j++) {
        for (long long i = 1; i + (1 << j) - 1 <= n; i++) {
            sparseMin[i][j] = min(sparseMin[i][j - 1], sparseMin[i + (1 << (j - 1))][j - 1]);
            sparseMax[i][j] = max(sparseMax[i][j - 1], sparseMax[i + (1 << (j - 1))][j - 1]);
        }
    }
}

long long qMin(long long l, long long r) {
    long long k = __lg(r - l + 1);
    return min(sparseMin[l][k], sparseMin[r - (1 << k) + 1][k]);
}

long long qMax(long long l, long long r) {
    long long k = __lg(r - l + 1);
    return max(sparseMax[l][k], sparseMax[r - (1 << k) + 1][k]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        for (long long i = 1; i <= n; i++) cin >> a[i];
        
        // Extend the array to handle circular ranges
        for (long long i = n + 1; i <= n; i++) 
            a[i] = a[i - n];
        
        build(n);

        if (n == k) { 
            cout << 0 << endl; 
            continue; 
        }

        long long i=1, j=n-k;
        long long ans = LLONG_MAX;

        // Check all possible segments in the circular array
        while(j<=n) {
            long long currentMin = qMin(i, j);
            long long currentMax = qMax(i, j);
            long long tem = ans;
            ans = min(ans, currentMax-currentMin);
            i++; j++;
        }

        long long ans1 =(ans+1)/2ll;
        if(k==0){
            cout<<ans1<<endl;
            continue;
        }
        k--;
        a[n+1]=a[1];
        n++;
        build(n);

        i=1, j=n-k;
        
        ans = LLONG_MAX;

        // Check all possible segments in the circular array
        while(j<=n) {
            long long currentMin = qMin(i, j);
            long long currentMax = qMax(i, j);
            long long tem = ans;
            ans = min(ans, currentMax-currentMin);
            i++; j++;
        }

        long long ans2 =(ans+1)/2ll;

        cout<<min(ans1, ans2)<<endl;

    }
}
