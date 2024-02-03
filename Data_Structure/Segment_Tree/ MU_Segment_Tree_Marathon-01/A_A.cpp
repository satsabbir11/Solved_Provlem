#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        int cnt [3]={};
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(x%3){
                cnt[x%3]++;
            }else ans++;
        }
        int mn = min(cnt[1], cnt[2]);
        ans+=mn;
        cnt[1]-=mn;
        cnt[2]-=mn;

        ans+=cnt[1]/3;
        ans+=cnt[2]/3;

        cout<<ans<<endl;
    }
}
