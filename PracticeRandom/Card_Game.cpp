#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j
#define all(s) s.begin(), s.end()

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin>>n>>x;
        
        long long tot=0, ev=0, od=0;

        ev=od=n/2;
        if(n%2) od++;

        // cout<<od<<" "<<ev<<endl;

        if(x%2){
            od--;
            tot=od;
        }else{
            ev--;
            tot=ev;
        }

        cout<<tot<<endl;
    }
}