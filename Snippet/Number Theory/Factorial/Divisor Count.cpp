long long factDivisorsCnt(long long n)
{
    long long res = 1;
    for (int i = 0; primes[i] <= n; i++)
    {
        long long exp = 0;
        long long p = primes[i];
        while (p <= n)
        {
            exp += (n / p);
            p *= primes[i];
        }
        res *= (exp + 1);
    }
    return res;
}