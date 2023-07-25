#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }

        map<int ,int> ans;

        for(int i=1;i<=n;i++){
            for(int j=1; j*j<=i;j++){
                if(i%j==0){
                    ans[i]+= mp[j];
                    if(j*j!=i) ans[i]+= mp[i/j];
                }
            }
        }

        int sum=0;

        for(int i=1;i<=n;i++){
            sum = max (sum, ans[i]);
        }
        cout<<sum<<endl;

    }
}