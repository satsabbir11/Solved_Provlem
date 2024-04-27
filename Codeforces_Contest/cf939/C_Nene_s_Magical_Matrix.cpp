#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin>>t;
    while(t--){
        long long n, cnt=0; cin>>n;
        for(long long i=1;i<=n;i++) cnt+=i*(i+i-1);

        cout<<cnt<<" "<<2*n<<endl;

        int ii=n, jj=n;
      
        for(long long i=1;i<=2*n;i++){
            if(i%2) cout<<1<<" "<<ii--<<" ";
            else cout<<2<<" "<<jj--<<" ";
            for(long long j=1;j<=n;j++) cout<<j<<" ";
            cout<<endl;
        }
    }
}