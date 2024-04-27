#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n, c, d;
        cin>>n>>c>>d;

        int a[n*n+2];
        map<int, int>mp;
        for(int i=1;i<=n*n;i++) {cin>>a[i]; mp[a[i]]++;}

        sort(a+1, a+1+n*n);
        int st = a[1];
        int l, dw;
        l=dw=st;

        bool f=true;

        for(int i=1;i<=n;i++){
            l=dw;
            dw+=c;
            for(int j=1;j<=n;j++){
                //cout<<l<<" ";
                if(mp[l]<=0) f=false;
                if(!f) break;
                mp[l]--;
                l+=d;
            }
            if(!f) break;
            //cout<<endl;
        }

        cout<<(f?"YES":"NO")<<endl;
    }
}