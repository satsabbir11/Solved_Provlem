#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s[n+5];

        for(int i=0;i<n;i++) cin>>s[i];
        string ans = s[0];

        for(int i=0;i<n;i++){
            bool one, zero;
            one = zero = false;
            for(int j=0;j<n;j++){
                if(s[j][i]=='0') zero = true;
                else one = true;
            }
            if(!one or !zero){

            }
        }
    }
}

