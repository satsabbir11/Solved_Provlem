#include <bits/stdc++.h>
using namespace std;

const int N = 1e8;
int prime[N / 32 + 5];

bool Check(int N, int pos) { return (bool)(N & (1 << pos)); }
int Set(int N, int pos) { return N = N | (1 << pos); }

void sieve()
{
    for (int i = 3; i * i <= N; i += 2)
    {
        if (!Check(prime[i / 32], i & 31))
            for (int j = i * i; j <= N; j += 2 * i)
                prime[j / 32] = Set(prime[j / 32], j & 31);
    }
}

int main()
{
    sieve();
    int cnt = 0;
    cout << 2 << endl;
    for (int i = 3; i <= N; i += 2)
    {
        if (!Check(prime[i / 32], i & 31)){
            cnt++;
            if(cnt%100==0) cout << i << endl;
        }
    }
}