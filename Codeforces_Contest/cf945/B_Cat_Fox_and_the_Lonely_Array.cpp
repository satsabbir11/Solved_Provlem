#include<bits/stdc++.h>
using namespace std;


int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        
        long long a[n+2], ans = n, cumOr[n+2]={};
        for(long long i=1;i<=n;i++){
            cin>>a[i];
            if(i==1) cumOr[i]=a[i];
            else cumOr[i] = cumOr[i-1] | a[i];
        }

        for(long long i=3;i<=3;i++){
            set<long long>st;
            for(long long j=1; j<=n-i+1;j++){
                if(j+i-1 > n) break;
                long long orValue = cumOr[j+i-1] ^ cumOr[j-1];
                cout<<cumOr[j+i-1]<<" "<<cumOr[j-1]<<" "<<orValue<<" "<<i<<endl;
                st.insert(orValue);
                //if(st.size()!=1) break;
            }
            cout<<endl;
            if(st.size()==1) ans = min(i, ans);
        }

        cout<<ans<<endl;
    }
}