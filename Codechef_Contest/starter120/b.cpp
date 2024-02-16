#include<bits/stdc++.h>
using namespace std;


int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        
        long long a[2*n+2];
        pair<long long, long long>cnt[n+2];
        map<long long, long long>mp;
        for(long long i=1;i<=2*n;i++){
            cin>>a[i];
        }

        for(long long i=1;i<=2*n;i++){
            if(mp[a[i]]){
                cnt[a[i]].first=i-mp[a[i]]-1;
                cnt[a[i]].second=a[i];
            }
            mp[a[i]]=i;
        }

        sort(cnt+1, cnt+1+n);

        for(long long i=n;i>=1;i--) cout<<cnt[i].second<<" ";
        cout<<endl;
        
    }
}