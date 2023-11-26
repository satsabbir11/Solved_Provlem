#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"not divisible":"divisible")
#define loj(i,j) "Case "<<i<<": "<<j

long long count5(long long n){
    long long ans =0;
    for(long long i=5;i<=n;i*=5){
        ans += (n/i);
    }
    return ans;
}


int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    for(long long i=1;i<=t;i++){
        long long n;
        cin>>n;

        long long l=1, r=1e18, ans=-1;

        while(l<=r){
            long long mid = l+(r-l)/2;
            if(count5(mid)<n) l = mid+1;
            else if(count5(mid)>n) r = mid-1;
            else{
                ans = mid;
                r= mid-1;
            }
        }
        if(ans==-1) cout<<loj(i, "impossible")<<endl;
        else cout<<loj(i, ans)<<endl;
    }
}