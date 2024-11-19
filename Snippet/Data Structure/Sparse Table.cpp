const int N = 2e5 + 5, K = 20;

struct SparseTable {
    long long a[N], sparseAll[N][K][8];

    long long lcm(long long x, long long y) {
        return (x / __gcd(x, y)) * y;
    }

    void build(int n) {
        for (int i = 1; i <= n; i++) 
            for (int j = 0; j < 8; j++) 
                sparseAll[i][0][j] = a[i];
        for (int j = 1; j < K; j++) 
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                sparseAll[i][j][0] = min(sparseAll[i][j - 1][0], sparseAll[i + (1 << (j - 1))][j - 1][0]);
                sparseAll[i][j][1] = max(sparseAll[i][j - 1][1], sparseAll[i + (1 << (j - 1))][j - 1][1]);
                sparseAll[i][j][2] = sparseAll[i][j - 1][2] + sparseAll[i + (1 << (j - 1))][j - 1][2];
                sparseAll[i][j][3] = __gcd(sparseAll[i][j - 1][3], sparseAll[i + (1 << (j - 1))][j - 1][3]);
                sparseAll[i][j][4] = lcm(sparseAll[i][j - 1][4], sparseAll[i + (1 << (j - 1))][j - 1][4]);
                sparseAll[i][j][5] = sparseAll[i][j - 1][5] ^ sparseAll[i + (1 << (j - 1))][j - 1][5];
                sparseAll[i][j][6] = sparseAll[i][j - 1][6] & sparseAll[i + (1 << (j - 1))][j - 1][6];
                sparseAll[i][j][7] = sparseAll[i][j - 1][7] | sparseAll[i + (1 << (j - 1))][j - 1][7];
            }
    }

    long long qMin(int l, int r) {
        int k = __lg(r - l + 1);
        return min(sparseAll[l][k][0], sparseAll[r - (1 << k) + 1][k][0]);
    }

    long long qMax(int l, int r) {
        int k = __lg(r - l + 1);
        return max(sparseAll[l][k][1], sparseAll[r - (1 << k) + 1][k][1]);
    }

    long long qSum(int l, int r) {
        int k = __lg(r - l + 1);
        return sparseAll[l][k][2] + sparseAll[r - (1 << k) + 1][k][2];
    }

    long long qGcd(int l, int r) {
        int k = __lg(r - l + 1);
        return __gcd(sparseAll[l][k][3], sparseAll[r - (1 << k) + 1][k][3]);
    }

    long long qLcm(int l, int r) {
        int k = __lg(r - l + 1);
        return lcm(sparseAll[l][k][4], sparseAll[r - (1 << k) + 1][k][4]);
    }

    long long qXor(int l, int r) {
        int k = __lg(r - l + 1);
        return sparseAll[l][k][5] ^ sparseAll[r - (1 << k) + 1][k][5];
    }

    long long qAnd(int l, int r) {
        int k = __lg(r - l + 1);
        return sparseAll[l][k][6] & sparseAll[r - (1 << k) + 1][k][6];
    }

    long long qOr(int l, int r) {
        int k = __lg(r - l + 1);
        return sparseAll[l][k][7] | sparseAll[r - (1 << k) + 1][k][7];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    SparseTable st;
    for (int i = 1; i <= n; i++) cin >> st.a[i];
    st.build(n);
    while (q--) {
        int l, r, type;
        cin >> l >> r >> type;
        //print what u want
    }
}