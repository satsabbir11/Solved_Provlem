#include <bits/stdc++.h>
using namespace std;

const int N = 1e8;
bitset<N>prime;

void sieve()
{
    for (int i = 3; i * i <= N; i += 2)
    {
        if (!prime[i])
            for (int j = i * i; j <= N; j += 2 * i)
                prime[j] = true;
    }
}

int main()
{
    sieve();
    int cnt = 0;
    cout << 2 << endl;
    for (int i = 3; i <= N; i += 2)
    {
        if (!prime[i]){
            cnt++;
            if(cnt%100==0) cout << i << endl;
        }
    }
}