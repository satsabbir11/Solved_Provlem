#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    long long ans;
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        if(i==1){
            ans = x;
            continue;
        }
        ans = __gcd(ans, x);
    }
    long long cnt = 0;
    for(long long i=1;i*i<=ans;i++){
        if(ans%i==0){
            long long j = ans/i;
            if(i!=j) cnt++;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}