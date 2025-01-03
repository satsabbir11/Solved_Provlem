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
        
        vector<int>a(n), b(n);
        for(int i=1;i<=n;i++) cin>>a[i-1];
        b=a;
        sort(all(b));

        map<int, int>rank;

        for(int i=0; i<n; i++) rank[b[i]]=n-i;

        for(int i=0; i<n; i++) b[i]=rank[a[i]];

        int ans=n;

        for(int i=1;i<n;i++){
            if(abs(b[i]-b[i-1]) == 1) ans--;
        }
        cout<<ans<<endl;
    }
}