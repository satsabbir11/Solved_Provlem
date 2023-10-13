#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int changeBit(long long n, long long i){
    n=(((n>>i)^1)<<i);
    return n;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, m, xr=0;
        cin>>n>>m;
        vector<int>v(32, false);
        vector<int>p(m);
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;

            xr^=x;

            for(int i=0;i<32;i++){
                long long lastBit = (x>>i)&1;
                if(!lastBit) v[i]++;
                v[i]%=2;
            }
        }
        for(int i=0;i<m;i++) cin>>p[i];
        //cout<<v[0]<<endl;

        long long mx = xr, min = xr;

        for(int i=0;i<m;i++){
            long long ans = xr, ans2=xr;
            for(int j=0;j<32;j++){
                long long x = p[i];
                x=(x>>j)&1;
               // cout<<p[i]<<" "<<v[j]<<" "<<x<<endl;
                if(v[j] && x) ans = changeBit(ans, j);
            }

            mx=max(ans, mx);
        }

        cout<<mx<<endl;
    }
}