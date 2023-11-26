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
        long long x, y, n;
        cin>>x>>y>>n;

        n-=y;

        long long k = n/x;
        cout<<k*x+y<<endl;
    }
}