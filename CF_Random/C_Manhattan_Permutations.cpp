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
        long long in = n - 1;

        long long a[n+2];
        for(long long i=1;i<=n;i++) a[i]=i;

        if (k % 2)
        {
            cout << "NO" << endl;
            continue;
        }

        long long sum =0;

        while (in > 0)
        {
            sum+=(in * 2);
            in -= 2;
        }

    
        if (k > sum)
        {
            cout << "NO" << endl;
            continue;
        }


        long long l=n, r=1;

        while(k>0){
            if(2*(l-r)<=k){
                k-=2*(l-r);
                swap(a[l], a[r]);
                l--; r++;
            }else{
                r++;
            }
        }

    
        sum =0;
        for(long long i=1;i<=n;i++) sum+=abs(a[i]-i);

        cout<<"YES"<<endl;

        for(long long i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
}