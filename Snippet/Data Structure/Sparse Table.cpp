const int N = 2e5 + 5, K = 20; // K = log2(N)
int a[N], t[N][K];
void build(int n)
{
    for (int i = 1; i <= n; i++) t[i][0] = a[i];
    for (int j = 1; j < K; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            t[i][j] = min(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int query(int l, int r)
{
    int k = __lg(r - l + 1);
    return min(t[l][k], t[r - (1 << k) + 1][k]);
}