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

    int t=1;
    // cin >> t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        
        int a[n+2];
        for(int i=1;i<=n;i++) cin>>a[i];

        int l=n, r=n;
        int sum=0, cnt=0, f=0;

        while(l>=1){
            sum+=a[l];
            f++;
            while(sum>m and r>=l){
            // cout<<sum<<endl;
                sum-=a[r];
                r--;
                f--;
            }
            if(sum<=m){
                cnt=max(cnt, f);
            }
            l--;
        }

        cout<<cnt<<endl;
        
    }
}