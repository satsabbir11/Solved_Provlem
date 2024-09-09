#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int l; cin>>l;
        string s; cin>>s;
        sort(s.begin(), s.end());

        string ans;
        for(int i=0; i<l/2; i++){
            ans+=s[i];
            ans+=s[l-i-1];
        }

        if(l&1) ans+=s[l/2];
        cout<<ans<<endl;
    }
}