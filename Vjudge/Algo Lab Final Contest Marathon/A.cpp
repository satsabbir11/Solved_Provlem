#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

  
        long long n, m;
        cin>>n>>m;
        
        long long a[n+2];
        for(long long i=1;i<=n;i++) cin>>a[i];

        long long st = 1;
        bool f=false;

        while(1){
            if(st>m) break;
            if(st==m) f=true;
            st+=a[st];
        }

        cout<<con<<endl;
   
}