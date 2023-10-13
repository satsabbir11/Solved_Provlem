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
        long long n;
        cin>>n;
        
        if(n<=6 || n==9) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            if(n%3==0) cout<<4<<" "<<1<<" "<<n-5<<endl;
            else cout<<2<<" "<<1<<" "<<n-3<<endl;
        }
    }
}