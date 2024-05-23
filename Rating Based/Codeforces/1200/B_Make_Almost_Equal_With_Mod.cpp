#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin>>t;
    while(t--){
        long long n; cin>>n;
        long long a[n+2], cnt=0, mn=1e18;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
            mn = min(mn, a[i]);
            if(a[i]%2) cnt++;
        }
        if(cnt!=n and cnt) cout<<2<<endl;
        else{
            long long base = 4;
            while(1){
                set<long long>st;
                for(long long i=1;i<=n;i++) st.insert(a[i]%base);
                if(st.size()==2) break;
                base*=2;
            }
            cout<<base<<endl;
        }
    }
}