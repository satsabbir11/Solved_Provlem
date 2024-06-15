#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int, int>mp;
        
        int j=n;
        while(j--){
            int x;
            cin>>x;
            mp[x]++;
        }

        int ans =0;

        for(int i=1;i<=n;i++){
            int cnt =0;
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    cnt+=mp[j];
                    if(j!= (i/j)) cnt+=mp[i/j];
                }
            }
            ans = max(ans,cnt);
        }
        cout<<ans<<endl;
    }
}