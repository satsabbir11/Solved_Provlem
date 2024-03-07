int trailingZeroes(int n)
{
    int c = 0, f = 5;
    while (f <= n)
    {
        c += n / f;
        f *= 5;
    }
    return c;
}