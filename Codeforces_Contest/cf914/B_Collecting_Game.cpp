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
        
        vector<pair<int, int>>p(n);

        for(long long i=0;i<n;i++){
            cin>>p[i].first;
            p[i].second = i;
        }

        sort(p.begin(), p.end());
        long long cum[n];

        cum[0] = p[0].first;
        long long ans[n];

        for(long long i=1;i<n;i++){
            cum[i] = cum[i-1] + p[i].first;
        }

        for(long long i=n-1;i>=0;i--){
            if(i==n-1) ans[p[i].second] = i;
            else if(cum[i]>=p[i+1].first) ans[p[i].second] = ans[p[i+1].second];
            else ans[p[i].second] = i;
        }

        for(long long i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}