#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        n/=2;
        long long x=n/2, y=(n+1)/2;
        cout<<x*y<<endl;
    }

}
