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
        
        int mx =0;
        for(int i=1;i<=n;i++){
            int x; cin>>x;
            if(x>mx) cout<<1<<" ";
            else cout<<0<<" ";
            mx=max(mx, x);
        }
        cout<<endl;
    }
}