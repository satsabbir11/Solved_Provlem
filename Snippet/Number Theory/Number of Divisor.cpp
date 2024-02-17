#define nn 1000010115.
long long int notprime[nn] = {}, prime[nn];
long long numberofDivisor(long long n)
{
    long long int c = 1, i, j, ans = 1;
    for (i = 3; i * i <= nn; i += 2)
    {

        if (!notprime[i])
        {
            for (j = i * i; j <= nn; j += i)
                notprime[j] = 1;
        }
    }
    prime[c++] = 2;
    for (i = 3; i <= nn; i += 2)
    {
        if (!notprime[i])
        {

            prime[c++] = i;
        }
    }

    for (i = 1; i <= nn && prime[i] * prime[i] <= n; i++)
    {
        if (n % prime[i] == 0)
        {
            int cnt = 1;
            while (n > 1 && n % prime[i] == 0)
            {
                n /= prime[i];
                cnt++;
            }
            ans *= cnt;
        }
    }
    if (n != 1)
        ans *= 2;
}