// SOD of n^m:
//(P1e1 +1 – 1 / P1 – 1). (P2e2 +1 – 1 / P2 – 1)..... (Prer +1 – 1 / Pr – 1)
ll primeFact(ll n, int m)
{
    ll sum = 1;
    for (int i = 0; i < primes.size() && primes[i] <= n; i++)
    {
        ll cnt = 0, p = primes[i];
        if (n % p == 0)
        {
            while (n % p == 0)
                cnt++, n /= p;
            cnt = cnt * m + 1;
            ll calc = (bigMod(p, cnt, MOD) + MOD - 1) % MOD;
            calc *= bigMod(p - 1, MOD - 2, MOD);
            calc %= MOD;
            sum = (sum * calc) % MOD;
        }
    }
    if (n > 1)
    {
        ll calc = (bigMod(n, 1 + m, MOD) + MOD - 1) % MOD;
        calc *= bigMod(n - 1, MOD - 2, MOD);
        calc %= MOD;
        sum = (sum * calc) % MOD;
    }
    return sum;
}

// Sod
sod(n) = (p1 ^ (e1 + 1) - 1) / (p1 - 1)
