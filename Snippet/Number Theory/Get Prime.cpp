#define INF 1000005
int prime[INF];
bool vis[INF];

void getPrime()
{
    int k = 1;
    prime[k++] = 2;
    for (long long i = 3; i <INF; i += 2)
    {
        if (!vis[i] && i % 2)
            prime[k++] = i;
        for (long long j = i * i; j < INF; j += i)
        {
            vis[j] = true;
        }
    }
}