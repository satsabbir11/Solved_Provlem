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
        map<long long, long long>mp;
        vector<long long>v;

        for(long long i=1;i<=n;i++){
            cin>>a[i];
            mp[a[i]]++;
            if(mp[a[i]]==1) v.push_back(a[i]);
        }

        long long l = v.size(), ans=0;

        for(long long i=0; i<n-2; i+=2){
            long long x = v[i], y = v[i+1], z = v[i+2];
            long long ans2=0;
            if(x-3>=0) ans2+=pow(2, x-3);
            if(y-3>=0) ans2+=pow(2, y-3);
            if(z-3>=0) ans2+=pow(2, z-3);

            ans+=ans2;

        }
        cout<<ans<<endl;
    }
}