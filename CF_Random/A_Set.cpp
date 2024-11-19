#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j
#define all(s) s.begin(), s.end()

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long l, r, k;
        cin>>l>>r>>k;
    
        long long ans = l;
        long long cnt=0, a=0;
        while(ans<=r){
            cnt++;
            a=ans;
            if(cnt==k) break;
            ans*=2;
        }

        ans = r-a-1;
        cout<<a<<endl;
        // if(k<=cnt) cout<<ans<<endl;
        // else cout<<0<<endl;
    }
}