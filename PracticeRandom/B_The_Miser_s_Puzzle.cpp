#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin>>t;
    long long tt=1;
    while(t--){
        long long n; cin>>n;
        long long lcm=1;
        for(long long i=1;i<=n;i++){
            long long x; cin>>x;
            long long lc = (x*lcm)/__gcd(x, lcm);
            lcm = lc;
        }
        cout<<"Case "<<tt++<<": "<<35*lcm<<endl;
    }
}