#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        string s, m;
        cin>>s>>m;

        int n = s.length(), g=0;

         for(int i=0;i<n;i++){
            int ff = s[i]-'0', ss = m[i]-'0';

            //cout<<ff<<" "<<ss<<endl;

            if(ff<ss){
                swap(s[i], m[i]);
                g=i+1;
                break;
            }else if(ff>ss){
                g=i+1;
                break;
            }
        }

        for(int i=g;i<n;i++){
            int ff = s[i]-'0', ss = m[i]-'0';

            if(ff>ss) swap(s[i], m[i]);
        }
        cout<<s<<endl<<m<<endl;
    }
}