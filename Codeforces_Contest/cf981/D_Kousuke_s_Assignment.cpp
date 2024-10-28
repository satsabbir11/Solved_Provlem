#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while (t--)
    {
        int n; cin>>n;
        int a[n+2];

        for (int i = 1; i <= n; i++) {
            cin>>a[i];
        }

        long long sum=0;
        map<long long, bool>mp;
        mp[0]=true;
        int cnt =0;

        for (int i = 1; i <= n; i++) {
            sum+=(long long)a[i];
            if(mp[sum]){
                //cout<<i<<" "<<sum<<endl;
                cnt++;
                mp.clear();
            }
            mp[sum]=true;
        }

        cout<<cnt<<endl;
    }
    
}
