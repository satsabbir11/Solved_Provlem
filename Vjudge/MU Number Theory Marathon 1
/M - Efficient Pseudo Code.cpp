#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con(f) (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

long long MOD = 1000000007;

long long bigMod(long long a, long long b)
{
    if (!b)
        return 1;
    long long res = bigMod(a, b >> 1);
    long long ans = (res * res) % MOD;
    if (b % 2)
        ans = (ans * a) % MOD;
    return ans;
}

long long inverseMod(long long a)
{
    return bigMod(a, MOD - 2);
}

void getPrimeFactorization(vector<long long> &primes, map<long long, long long> &freq, long long n)
{
    if (n % 2 == 0)
    {
        primes.push_back(2);
        while (n % 2 == 0)
        {
            freq[2]++;
            n >>= 1;
        }
    }

    for (long long i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            primes.push_back(i);
            while (n % i == 0)
            {
                freq[i]++;
                n /= i;
            }
        }
    }

    if (n > 1)
    {
        freq[n]++;
    }

    if (freq[n] == 1)
        primes.push_back(n);
}

long long getSumOfAllDivisor(long long a, long long b)
{
    vector<long long> primes;
    map<long long, long long> freq;

    long long ans = 1;

    getPrimeFactorization(primes, freq, a);

    for (long long p : primes)
    {
        long long lob = bigMod(p, freq[p]*b + 1) - 1;
        if (lob < 0)
            lob += MOD;
        long long hor = inverseMod(p - 1);

        lob *= hor;

        ans = ((ans % MOD) * (lob % MOD)) % MOD;
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    for (long long k = 1; k <= t; k++)
    {
        long long a, b;
        cin >> a >> b;

        long long ans = getSumOfAllDivisor(a, b);

        cout << loj(k, ans) << endl;
    }
}