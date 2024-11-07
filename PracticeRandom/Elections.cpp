#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j
#define all(s) s.begin(), s.end()

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin>>n>>x;
        
        long long a[n+2], cnt=0;
        for(long long i=1;i<=n;i++) cin>>a[i];

        for(long long i=1;i<=n;i++){
            long long x;
            cin>>x;
            if(x>=a[i]) a[i]=abs(x-a[i])+1;
            else a[i]=0;
        }

        sort(a+1, a+1+n);
        for(int i=1;i<=n;i++){
            //cout<<a[i]<<" ";
            if(a[i]){
                if(x>=a[i]) x-=a[i];
                else break;
            }
            cnt=i;
        }
        bool f=(cnt>n/2);
        cout<<con<<endl;
    }
}