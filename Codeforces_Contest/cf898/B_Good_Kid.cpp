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
        for(long long i=1;i<=n;i++) cin>>a[i];

        long long cnt =1, pr=1;

        sort(a+1, a+1+n);

        for(long long i=1;i<=n;i++){
            if(a[i]==0){
                a[i]++;
                cnt--;
            }
            if(cnt==0) break;
        }

         for(long long i=1;i<=n;i++){
            if(cnt==0) break;
            if(a[i]!=0){
                a[i]++;
                cnt--;
            }
            if(cnt==0) break;
        }

        for(long long i=1;i<=n;i++) pr*=a[i];
        cout<<pr<<endl;
    }
}