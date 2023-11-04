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
        
        long long a[n+2];
        for(long long i=0;i<n;i++) cin>>a[i];

        bool f=true;

        for(int i=0;i+1<n && f;i++){
            if(a[i]>a[i+1] && ((i+1)&i)) f=false;
        }

        cout<<con<<endl;
    }
}