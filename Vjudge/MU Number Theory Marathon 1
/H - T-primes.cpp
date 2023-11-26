#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

vector<bool> isPrime(long long n = 1e6)
{
    vector<bool> vis(n + 5);
    vis[1] = true;
    for (long long i = 2; i <= n; i++)
    {
        if (!vis[i])
            for (long long j = i * i; j <= n; j += i)
                vis[j] = true;
    }
    return vis;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    vector<bool> vis = isPrime();
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        long long sq = sqrt(n);

        bool f = (sq == sqrt(n) && !vis[sq]);
        cout << con << endl;
    }
}