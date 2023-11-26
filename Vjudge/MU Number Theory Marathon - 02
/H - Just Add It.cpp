#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

#define p 10000007

long long bigMod(long long n, long long m)
{
    if (m == 0)
        return 1;
    long long res = bigMod(n, m / 2);
    long long ans = (res % p * res % p) % p;
    if (m % 2)
        ans = (ans * n % p) % p;
    return ans;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
    while (1) {
        long long n, k;
        cin>>n>>k;
        if(!n && !k) break;
        cout<<(bigMod(n, k) + (2*bigMod(n-1, k))%p + bigMod(n, n) + (2*bigMod(n-1, n-1))%p)%p<<endl;
    }
}