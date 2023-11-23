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

        
        long long cnt1= 0, cnt2 = 0, cnt = 0, ans = INT_MIN;
        for(long long i=1;i<=n;i++){
            long long x;
            cin>>x;

            if(x<=0){
                cnt++;
                ans = max(ans, x);
                continue;
            }

            if(i%2){
                cnt1+=x;
            }
            else {
                cnt2+=x;
            }
        }

        if(cnt == n) cout<<ans<<endl;
        else cout<<max( cnt1, cnt2 )<<endl;
    }
}