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
        int x, y;
        cin>>x>>y;
        if(2*x<=y) cout<<x<<" "<<2*x<<endl;
        else cout<<-1<<" "<<-1<<endl;
    }
}