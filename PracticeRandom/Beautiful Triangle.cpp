#include <bits/stdc++.h>
using namespace std;

long long ncr(long long n){
    long long ans =1;
    for(long long i=n-2;i<=n;i++) ans*=i;
    return ans/6;
}

int main(){
    long long t; cin>>t;
    while(t--){
        long long n, sum=0; cin>>n;
        map<long long, long long>mp;

        for(long long i=1;i<=n;i++){
            long long x;
            cin>>x;
            mp[x]++;
        }

        for(auto [x, y]: mp){
            if(y>2) sum+=ncr(y);
        }
        cout<<sum<<endl;
    }
}