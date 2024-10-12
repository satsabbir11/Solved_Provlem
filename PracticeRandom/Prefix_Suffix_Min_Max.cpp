#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ase=0;
        int lagbo[n+2];
        for(int i=1;i<=n;i++) cin>>lagbo[i];
        ase = -2000000;
        for(int i=1; i<=n; i++){
            int cnt = lagbo[i]-ase;
            cout<<cnt<<" ";
            ase+=cnt;
        }
        cout<<endl; 
    }
}