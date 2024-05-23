#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    int q;
    cin>>q;
    while(q--){
        string t;
        cin>>t;

        int i=0, j=0;
        bool f=true;

        while(1){
            if(s[i]==t[j]){
                i++; j++;
            }
            else i++;
            if(j==t.size()) break;
            if(i==s.size()){
                f=false;
                break;
             }
        }

        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}