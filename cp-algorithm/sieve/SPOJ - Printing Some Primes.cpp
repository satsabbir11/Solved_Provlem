#include <bits/stdc++.h>
using namespace std;

#define inf 100000000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    bitset<inf> vis;

    long long k=1;

    cout << 2 << endl;

    for (long long i = 3; i <= inf; i += 2)
    {
        if (!vis[i])
        {
            k++;
            if(k%100==1) cout << i << endl;
            if (i * i <= inf) for (long long j = i * i; j <= inf; j += 2*i) vis[j] = true;
        }
    }
}

