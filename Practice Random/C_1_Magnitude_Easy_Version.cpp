#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<int> a(n + 2, 0);

        long long suff[n + 2], sum=0;

        for (long long i = 1; i <= n; i++)
            cin >> a[i];

        for (long long i = n; i >=1; i--){
            suff[i] = suff[i+1]+a[i];
        }

        for (long long i = 1; i <= n; i++){
            if(a[i]<0 and a[i+1]>=0){
                long long x = sum+a[i]+suff[i+1], y = abs(sum+a[i])+suff[i+1];
                if(x<y) sum = abs(sum+a[i]);
                else sum = sum+a[i];
            }else sum+=a[i];

            cout<<a[i]<<" "<<sum<<endl;
        }
        cout<<sum<<endl;
    }
}