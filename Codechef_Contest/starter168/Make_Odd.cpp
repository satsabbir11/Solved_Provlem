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
        
        string ss, tt; cin>>ss>>tt;
        int cnt11=0, cnt01=0;

        for(int i=0;i<n;i++){
            if(ss[i]==tt[i] and ss[i]=='1') cnt11++;
            else if(tt[i]=='1' or ss[i]=='1') cnt01++;
        }

        if(cnt11%2 or cnt01) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}