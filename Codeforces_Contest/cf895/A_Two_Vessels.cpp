#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        double a, b, c;
        cin>>a>>b>>c;
        
        a = abs(a-b)/2;

        a /= c;

        cout<<ceil(a)<<endl;
        
    }
}