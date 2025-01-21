#include <bits/stdc++.h>
using namespace std;

#define int long long

int lcm(int x, int y){
    return (x * y) / __gcd(x, y);
}

int lcm(int x, int y, int z){
    return lcm(lcm(x, y), z);
}



int32_t main(){
    int n; cin>>n;

    int x1=max(1ll, n-1), x2=max(1ll, n-2), x3=max(1ll, n-3), x4=max(1ll, n-4);
    
    cout<<max({lcm(n, x1, x2), lcm(n, x1), lcm(x1, x2), lcm(x2, x3), lcm(x3, x4), lcm(x1, x2, x3), lcm(n, x1, x3), lcm(x1, x2, x4), lcm(x2, x3, x4)})<<endl;
}