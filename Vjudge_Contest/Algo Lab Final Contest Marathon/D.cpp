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
        long long n, cnt=0;
        cin>>n;
        
        string s, t;
        cin>>s>>t;

        for(int i=0;i<n;i++){
            if(t[i]=='1'){
                if(i>0 && s[i-1]=='1'){
                    cnt++;
                    s[i-1ll]='2';
                }
                else if(s[i]=='0'){
                    cnt++;
                    s[i]='2';
                }
                else if(i<(n-1) && s[i+1ll]=='1'){
                    cnt++;
                    s[i+1ll]='2';
                }
            }
        }
        cout<<cnt<<endl;
    }
}