#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        int m, k, a1, ak, ans = 0;
        cin >> m >> k >> a1 >> ak;

        int needK = m/k;
        int needOne = m%k;
        
        int minOne = min(a1, needOne);
        a1-=minOne; needOne-=minOne; // delete a1 from needOne
        ans+=needOne; // needOne is always less than k, so k cant replace it

        ak+=a1/k; // if a1 exist make it to k
        needK -= min(needK, ak); // delete ak from needK
        
        ans+=needK;
        cout<<ans<<endl;
    }
}