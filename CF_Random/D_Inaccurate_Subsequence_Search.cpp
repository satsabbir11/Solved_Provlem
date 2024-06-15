#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    int x=0;
    while(t--){
        x++;
        int n, m, k; cin>>n>>m>>k;
        int a[n+2], b[m+2];
        map<int, int>have, need;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i<=m) have[a[i]]++; //we have
        }

        int cnt=0;

        for(int i=1;i<=m;i++){
            cin>>b[i];
            need[b[i]]++; //we need
        }

        for(auto [x, y]: need){
            cnt+=min(need[x], have[x]); //total ase
        }

        int l=1, r=m, ans=(cnt>=k);

        while(r<n){
            have[a[l]]--;
            if(have[a[l]]<need[a[l]]) cnt--; //ekta komlo mane ami k theke dure shorlam, jehetu ata need
            r++; l++;
            have[a[r]]++;
            if(have[a[r]]<=need[a[r]]) cnt++; // need er theke barle ashole amar kono lav nai. example: 9 9 9, 9 9 5
            
            ans+=(cnt>=k);
            //cout<<r<<" "<<cnt<<" "<<ans<<endl;
        }

        cout<<ans<<endl;
    }
}