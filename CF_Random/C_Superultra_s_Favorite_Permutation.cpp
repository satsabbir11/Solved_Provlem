#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j
#define all(s) s.begin(), s.end()

bool isPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        if (n <= 4)
        {
            cout << -1 << endl;
            continue;
        }

        long long tot = n, ans;
        if(n%2==0) tot--;

        for (long long i = 2; i <= n; i+=2){
            if(!isPrime(tot+i)){
                ans = i;
                break;
            }
        }

        for(long long i=1; i<=n; i+=2) cout<<i<<" ";
        cout<<ans<<" ";
        for(long long i=2; i<=n; i+=2) if(ans!=i) cout<<i<<" ";
        cout<<endl;
    }
}