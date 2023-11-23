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
        map<int, int>mp;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
            mp[a[i]]=i;
        }
        int cnt =0;

        for(long long i=1;i<n;i++) {
            if(mp[i]>mp[i+1]) cnt++;
        }
        cout<<cnt<<endl;
    }
}