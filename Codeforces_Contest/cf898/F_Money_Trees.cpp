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
        long long n, k, ans=0;
        cin>>n>>k;
        
        long long a[n+2], b[n+2];
        for(long long i=1;i<=n;i++) cin>>a[i];
        for(long long i=1;i<=n;i++){
            cin>>b[i];
            if(a[i]<=k) ans=1;
        }


        long long point = -1, sum=0;

        for(long long i=2;i<=n;i++){
            if(b[i-1]%b[i]==0){
                if(point ==-1){
                    point = i-1;
                    sum+=a[point];
                }
                if((sum+a[i])<=k){
                    sum+=a[i];
                    ans = max(ans, i-point+1);
                }
                else{
                    sum-=a[point];
                    point++;
                    i--;
                }
            }
            else{
                point = -1;
                sum =0;
            }
        }
        cout<<ans<<endl;
    }
}