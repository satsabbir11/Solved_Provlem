#define MOD 1000000007
long long bigMod(long long a, long long b)
{
  a %= MOD;
  if (!b)
    return 1;
  long long res = bigMod(a, b / 2);
  long long ans = (res * res) % MOD;
  if (b % 2)
    ans = (ans * a) % MOD;
  return ans;
}

long long inverseMod(long long a)
{
  return bigMod(a, MOD - 2);
}


long long fact[MOD];
void factorial()
{
  fact[0] = 1;
  for (long long i = 1; i < MOD; i++)
    fact[i] = (((i % MOD) * (fact[i - 1] % MOD)) % MOD);
}

long long nCr(long long n, long long r)
{
  return ((fact[n] % MOD) * (inverseMod((fact[r] * fact[n - r]) % MOD) % MOD)) % MOD;
}