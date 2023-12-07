#include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    double d = sqrt(1 + 8.0 * n);
    int ans = (-1 + d) / 2;
    cout<<ans<<endl;
   }
}
