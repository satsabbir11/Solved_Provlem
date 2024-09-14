#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n], b[n], c[n];
        for (long long i = 0; i < n; i++)
            cin >> a[i];
        for (long long i = 0; i < n; i++)
            cin >> b[i];
        for (long long i = 0; i < n; i++)
            cin >> c[i];

        long long i = 0, ans = 0;
        while (i<n)
        {
            if ((k | a[i]) != k) break;
            ans |= a[i++];
        }
        i=0;
        while (i<n)
        {
            if ((k | b[i]) != k) break;
            ans |= b[i++];
        }
        i=0;
        while (i<n)
        {
            if ((k | c[i]) != k) break;
            ans |= c[i++];
        }

        //cout<<ans<<" "<<k<<endl;

        if(ans==k) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}