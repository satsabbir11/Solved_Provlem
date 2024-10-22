#include <bits/stdc++.h>
using namespace std;

// Maximum array size and logarithmic size for sparse table
const int N = 2e5 + 5, K = 20; // K = log2(N)

// Sparse table data structure supporting multiple operations
struct SparseTable {
    long long a[N]; // Input array
    long long sparseAll[N][K][8]; // Sparse table with different operations

    // Function to calculate LCM of two numbers
    long long lcm(long long x, long long y) {
        return (x / __gcd(x, y)) * y;
    }

    // Function to build the sparse table for all operations
    void build(int n) {
        // Initialize the sparse table for the first level (2^0 = 1)
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 8; j++) 
                sparseAll[i][0][j] = a[i]; // Initialize with the array elements
        }

        // Fill the sparse table using dynamic programming
        for (int j = 1; j < K; j++) { // Iterate over powers of 2
            for (int i = 1; i + (1 << j) - 1 <= n; i++) { // Iterate over valid ranges
                sparseAll[i][j][0] = min(sparseAll[i][j - 1][0], sparseAll[i + (1 << (j - 1))][j - 1][0]); // min
                sparseAll[i][j][1] = max(sparseAll[i][j - 1][1], sparseAll[i + (1 << (j - 1))][j - 1][1]); // max
                sparseAll[i][j][2] = sparseAll[i][j - 1][2] + sparseAll[i + (1 << (j - 1))][j - 1][2]; // sum
                sparseAll[i][j][3] = __gcd(sparseAll[i][j - 1][3], sparseAll[i + (1 << (j - 1))][j - 1][3]); // gcd
                sparseAll[i][j][4] = lcm(sparseAll[i][j - 1][4], sparseAll[i + (1 << (j - 1))][j - 1][4]); // lcm
                sparseAll[i][j][5] = sparseAll[i][j - 1][5] ^ sparseAll[i + (1 << (j - 1))][j - 1][5]; // xor
                sparseAll[i][j][6] = sparseAll[i][j - 1][6] & sparseAll[i + (1 << (j - 1))][j - 1][6]; // bitwise AND
                sparseAll[i][j][7] = sparseAll[i][j - 1][7] | sparseAll[i + (1 << (j - 1))][j - 1][7]; // bitwise OR
            }
        }
    }

    // Function to query the minimum in range [l, r]
    long long qMin(int l, int r) {
        int k = __lg(r - l + 1); // Find the largest power of 2 that fits in the range
        return min(sparseAll[l][k][0], sparseAll[r - (1 << k) + 1][k][0]);
    }

    // Function to query the maximum in range [l, r]
    long long qMax(int l, int r) {
        int k = __lg(r - l + 1);
        return max(sparseAll[l][k][1], sparseAll[r - (1 << k) + 1][k][1]);
    }

    // Function to query the sum in range [l, r]
    long long qSum(int l, int r) {
        int k = __lg(r - l + 1);
        return sparseAll[l][k][2] + sparseAll[r - (1 << k) + 1][k][2];
    }

    // Function to query the GCD in range [l, r]
    long long qGcd(int l, int r) {
        int k = __lg(r - l + 1);
        return __gcd(sparseAll[l][k][3], sparseAll[r - (1 << k) + 1][k][3]);
    }

    // Function to query the LCM in range [l, r]
    long long qLcm(int l, int r) {
        int k = __lg(r - l + 1);
        return lcm(sparseAll[l][k][4], sparseAll[r - (1 << k) + 1][k][4]);
    }

    // Function to query the XOR in range [l, r]
    long long qXor(int l, int r) {
        int k = __lg(r - l + 1);
        return sparseAll[l][k][5] ^ sparseAll[r - (1 << k) + 1][k][5];
    }

    // Function to query the bitwise AND in range [l, r]
    long long qAnd(int l, int r) {
        int k = __lg(r - l + 1);
        return sparseAll[l][k][6] & sparseAll[r - (1 << k) + 1][k][6];
    }

    // Function to query the bitwise OR in range [l, r]
    long long qOr(int l, int r) {
        int k = __lg(r - l + 1);
        return sparseAll[l][k][7] | sparseAll[r - (1 << k) + 1][k][7];
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    SparseTable st;

    // Read the array elements
    for (int i = 1; i <= n; i++) {
        cin >> st.a[i];
    }

    // Build the sparse table for all operations
    st.build(n);

    // Process each query
    while (q--) {
        int l, r, type;
        cin >> l >> r >> type;

        // Execute the appropriate query based on the type
        if (type == 0)
            cout << st.qMin(l, r) << endl; // Query minimum
        else if (type == 1)
            cout << st.qMax(l, r) << endl; // Query maximum
        else if (type == 2)
            cout << st.qSum(l, r) << endl; // Query sum
        else if (type == 3)
            cout << st.qGcd(l, r) << endl; // Query gcd
        else if (type == 4)
            cout << st.qLcm(l, r) << endl; // Query lcm
        else if (type == 5)
            cout << st.qXor(l, r) << endl; // Query xor
        else if (type == 6)
            cout << st.qAnd(l, r) << endl; // Query bitwise AND
        else if (type == 7)
            cout << st.qOr(l, r) << endl; // Query bitwise OR
    }

    return 0;
}
