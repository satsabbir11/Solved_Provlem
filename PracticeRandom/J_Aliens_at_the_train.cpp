#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        long long a[n + 2];
        for (long long i = 1; i <= n; i++)
            cin >> a[i];

        long long l, r;
        l = r = n;
        long long sum = 0, mum=LLONG_MAX;
        long long ans=0;
        while (l > 0)
        {
            sum += a[l--];
            while(sum>k and l<=r){
                sum-=a[r--];
            }
           // cout<<sum<<" "<<r<<" "<<l<<endl;
            if(sum<=k){
                //cout<<sum<<" "<<ans<<" "<<l<<" "<<r<<endl;
                if(ans<(r-l)){
                    ans = r-l;
                    mum=sum;
                }else if(ans==(r-l)){
                    ans = r-l;
                    mum=min(mum, sum);
                }
            }
        }

        cout<<mum<<" "<<ans<<endl;
    }
}