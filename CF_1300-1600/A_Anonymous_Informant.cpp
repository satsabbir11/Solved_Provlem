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
        long long n, k;
        cin>>n>>k;
        
        long long a[n+2];
        for(long long i=1;i<=n;i++) cin>>a[i];

        int s = a[n], afm = n; 
        bool f=true;

        /* we have two target,
        1. when the last position is in proper place than who is in the last position?
        */

        k= min(n, k); // for avoiding infinite loop

        while(k--){
            if(s>n){ //no number is bigger in the last position than n
                f=false;
                break;
            }
            afm+=(n-s);
            afm%=n;
            if(!afm) afm = n;
            s=a[afm];
        }
        cout<<con<<endl;
    }
}