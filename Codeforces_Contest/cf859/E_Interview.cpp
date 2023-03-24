#include<bits/stdc++.h>
using namespace std;


int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;

        long long a[n+1], cum[n+1]={0};
        for(long long i=1;i<=n;i++){
            cin>>a[i];
            cum[i]=cum[i-1]+a[i];
        }

        long long l=1, r=n;
        while(l<r){
            long long mid = (l+r)/2;

            long long sum = cum[mid]-cum[l-1];

            cout<<"? "<<mid-l+1;
            for(long long i=l;i<=mid;i++) cout<<" "<<i;
            cout<<endl;
            cout.flush();

            long long x;
            cin>>x;

            if(sum==x) l=mid+1;
            else r=mid;
        }

        cout<<"! "<<l<<endl;
        cout.flush();

    }
}
