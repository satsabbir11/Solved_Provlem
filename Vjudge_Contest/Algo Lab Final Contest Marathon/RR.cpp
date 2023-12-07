#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long
#define Max 32000
vector<long long> prime;
void sieve()
{
    bool isPrime[Max];
    for (int i = 0; i < Max; i++)
        isPrime[i] = true;
    for (int i = 3; i < Max; i += 2)
    {
        for (int j = i * i; j < Max; j += i)
            isPrime[j] = false;
    }
    prime.push_back(2);
    for (int i = 3; i < Max; i += 2)
    {
        if (isPrime[i])
            prime.push_back(i);
    }
}

void segment(long long l, long long r)
{
    bool isPrime[r - l + 1];
    for (int i = 0; i < r - l + 1; i++)
        isPrime[i] = true;
    for (int i = 0; prime[i] * prime[i] <= r; i++)
    {
        int curp = prime[i];
        long long base = (l / curp) * curp;
        if (base < l)
            base += curp;
        for (long long j = base; j <= r; j += curp)
            isPrime[j - l] = false;
        if (base == curp)
            isPrime[base - l] = true;
        if (l == 1)
            isPrime[0] = false;
    }
    for (int i = 0; i < r - l + 1; i++)
    {
        if (isPrime[i])
            cout << i + l << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;
    sieve();
    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        segment(l, r);
    }
}