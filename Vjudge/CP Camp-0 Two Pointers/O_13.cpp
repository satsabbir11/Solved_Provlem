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

    int t, i=1;
    cin >> t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        
        vector<int> a(n);
        for(int &x: a) cin>>x;

        cout<<"Case "<<i++<<": "<<endl;
        while(m--){
            int x, y; cin>>x>>y;
            int xx = lower_bound(all(a), x)-a.begin();
            int yy = lower_bound(all(a), y)-a.begin();

            // if(a[xx]==x) xx++;
            if(a[yy]==y) yy++;
            // cout<<x<<" "<<y<<endl;
            // cout<<xx<<" "<<yy<<endl;
            // cout<<endl;
            cout<<yy-xx<<endl;
        }
    }
}