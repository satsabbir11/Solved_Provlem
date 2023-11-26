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
        
        long long a[n+2], k=0;
        map<int, bool>mp;
        vector<int>p;
        for(long long i=1;i<=n;i++){
            int x;
            cin>>x;
            if(mp[x]) p.push_back(x);
            else a[++k]=x;
            mp[x]=true;
        }
        sort(a+1, a+1+k);

        for(long long i=1;i<=k;i++){
            cout<<a[i]<<" ";
        }
        for(int x: p) cout<<x<<" ";
        cout<<endl;
    }
}