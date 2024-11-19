int phi(int n)
{
    double res = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res *= (1.0 - (1.0 / i))
        }
    }
    if (n > 1)
        res *= (1.0 - (1.0 / n));
    return (int)(res);
}
