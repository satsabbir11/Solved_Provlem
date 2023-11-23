#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n, m;
    cin >> n >> m;

    if (m <= n)
    {
        cout << n - m << endl;
        return 0;
    }

    int one;

    int ans=0;
    while(m>n){
        if(m%2){
            m++;
            ans++;
        }
        ans++;
        m/=2;
        one = n-m;
    }

    cout<<ans+one<<endl;
}