#include <bits/stdc++.h>
using namespace  std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        bool f=false;

        for(int i=0; i<n-1; i++){
            if(s[i]=='1' and s[i+1]=='1'){
                f=true;
                break;
            }
        }

        if(s[0]=='1' or s[n-1]=='1') f=true;
        cout<<(f?"YES":"NO")<<endl;
    }
}