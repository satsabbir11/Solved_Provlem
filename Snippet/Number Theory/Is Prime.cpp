vector<bool> isPrime(long long n = 1e6)
{
    vector<bool> vis(n + 5);
    vis[1] = true;
    for (long long i = 3; i <= n; i+=2)
    {
        if (!vis[i])
            for (long long j = i * i; j <= n; j += i)
                vis[j] = true;
    }
    return vis;
}