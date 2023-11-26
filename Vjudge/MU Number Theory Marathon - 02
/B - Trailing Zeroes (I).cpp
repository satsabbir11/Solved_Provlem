#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "not divisible" : "divisible")
#define loj(i, j) "Case " << i << ": " << j
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    getPrime();

    long long t;
    cin >> t;
    for (long long i = 1; i <= t; i++)
    {
        long long n, ans = 1;
        cin >> n;
        for (long long i = 1; i < INF && prime[i] * prime[i] <= n; i++)
        {
            if(!prime[i]) break;
            if (n % prime[i] == 0)
            {
                long long cnt = 1;
                while (n % prime[i] == 0)
                {
                    cnt++;
                    n /= prime[i];
                    if (n == 0 || n == 1)
                        break;
                }
                ans *= cnt;
            }
        }
        if (n > 1)
            ans *= 2;
        cout << loj(i, ans - 1) << endl;
    }
}