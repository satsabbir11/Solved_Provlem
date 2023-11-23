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
        int x, y, k;
        cin>>x>>y>>k;

        if(x>=y) cout<<x<<endl;
        else{
            x=min(y, x+k);
            cout<<y+abs(x-y)<<endl;
        }
    }
}