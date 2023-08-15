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
        
        long long a[4];
        for(long long i=1;i<=3;i++) cin>>a[i];

        a[2] += a[3]/2;
        a[1] += min(a[3], ((a[3]+1)/2));

        if(a[1]<=a[2]) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
}