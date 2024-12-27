#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j
#define all(s) s.begin(), s.end()

#define bug(a) cout << #a << " : " << a <<endl;

#define int long long

int32_t main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;

        map<int, bool>mp;
        int a[n+2];
        for(int i=1; i<=n; i++) cin>>a[i];
        int ans = 0;
        for(int i=n;i>=1;i--){
            if(mp[a[i]]==false) ans+=i;
            mp[a[i]]=true;
        }

       cout<<ans<<endl;
    }
}