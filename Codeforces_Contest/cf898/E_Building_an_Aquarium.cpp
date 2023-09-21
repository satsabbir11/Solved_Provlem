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
        long long n, k;
        cin>>n>>k;
        
        long long a[n+2], sum =0, tot;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }

        sort(a+1, a+1+n);
       

        tot = a[n]*n-sum;
       // cout<<k-tot<<endl;

        if(tot<=k){
            k-=tot;
            long long ans = k/n;
            cout<<ans+a[n]<<endl;
        }
        else{
            long long sum =0, ans=0;
            for(long long i=2;i<=n;i++){
                sum = (a[i]-a[i-1])*(i-1);
                long long per = i-1;

                //cout<<sum<<endl;
                
                if(k>=sum){
                    ans=a[i];
                    k-=sum;
                }
                else{
                    ans = a[i-1]+ (k/per);
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }
}