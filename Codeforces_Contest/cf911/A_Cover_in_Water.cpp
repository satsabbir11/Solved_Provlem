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
        
        string s;
        cin>>s;

        int cnt =0, ans=0;
        bool f=false;
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                cnt++;
                ans++;
            }
            else{
                if(cnt>=3) f=true;
                cnt=0;
            }
        }

        if(cnt>=3) f=true;

        if(f) cout<<2<<endl;
        else cout<<ans<<endl;
    }
}