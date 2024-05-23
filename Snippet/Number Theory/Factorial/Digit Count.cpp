int factDigitCnt(int n)
{
    if (n <= 1)
        return n;
    double digits = 0;
    for (int i = 2; i <= n; i++)
    {
        digits += log10(i);
    }
    return floor(digits) + 1;
}