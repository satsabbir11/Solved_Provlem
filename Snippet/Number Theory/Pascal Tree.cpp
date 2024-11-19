void generatePascalsTriangle(int maxN)
{
    for (int n = 0; n <= maxN; n++)
    {
        pascalTriangle[n][0] = 1;
        for (int r = 1; r <= n; r++)
        {
            pascalTriangle[n][r] =
                pascalTriangle[n - 1][r - 1] +
                pascalTriangle[n - 1][r];
        }
    }
}
ll nCr(int n, int r) { return pascalTriangle[n][r]; }