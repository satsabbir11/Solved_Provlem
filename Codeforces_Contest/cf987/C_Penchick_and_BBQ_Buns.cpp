#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n%2==0){
            for(int i=1; i<=n/2; i++) cout<<i<<" "<<i<<" ";
        }
        else if(n<27) cout<<-1<<endl;
        else{
            int v[n+2]={};
            v[1]=v[10]=v[26]=1;
            v[11]=v[27]=2;
            int st=3, r=0;
            for(int i=1; i<=n; i++){
                if(!v[i]){
                    v[i]=st;
                    r++; r%=2;
                    if(r==0) st++;
                }
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
}