#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        
        long long a[n+2];

        a[1]=2;
        a[2]=3;

        for(long long i=3;i<=n;i++){
            long long x = a[i-1]+a[i-2];
            a[i]=a[i-1]+1;
            if((a[i]*3)%x==0) a[i]++;
        }
        for(long long i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}