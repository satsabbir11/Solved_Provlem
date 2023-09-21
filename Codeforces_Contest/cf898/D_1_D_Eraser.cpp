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
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;

        long long pw=k, ans =0;
        bool onn= false;

        for(int i=0;i<n;i++){
            if(!onn && s[i]=='B'){
                onn = true;
                pw=k;
                ans++;
                //cout<<i<<endl;
            }
             if(onn && pw){
                pw--;
                if(pw==0) onn = false;
             }
        }
        cout<<ans<<endl;
    }
}