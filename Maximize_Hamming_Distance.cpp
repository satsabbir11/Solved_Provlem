#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int k, n;
        cin>>k>>n;

        string s[n+1];
        for(int i=1;i<=n;i++) cin>>s[i];


        long long ans = 0;

        for(int i=0;i<k;i++){
            long long cnt0, cnt1, cntq;
            cnt0=cnt1=cntq=0;
            for(int j=1;j<=n; j++){
                if(s[j][i]=='0') cnt0++;
                else if(s[j][i]=='1') cnt1++;
                else cntq++;
            }

            int half = n/2;
            int mx = max(cnt0, cnt1);

           if(mx>=half) ans += (long long)mx * (long long)(n-mx);
           else ans += (long long)half * (long long)(n-half);

        }

        cout<<ans<<endl;
    }
}