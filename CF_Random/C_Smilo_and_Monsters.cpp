#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j
#define upperbound(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())

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

        vector<long long>a(n);
        for(long long &x: a) cin>>x;

        sort(a.begin(), a.end());
        long long sum = accumulate(a.begin(), a.end(), 0ll);
        long long doSnd = sum/2;
        long long ans = sum-doSnd;

        for(long long i = n-1;i>=0;i--){
            if(doSnd>0){
                doSnd-=a[i];
                ans++;
            }else break;
        }
        cout<<ans<<endl;
    }
}
