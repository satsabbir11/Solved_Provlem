#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   long long n;
   cin>>n;
   bool f=false;
   vector<long long>v(n+2, 1);
   for(long long i=2;i<=n+1;i++){
    for(long long j=i*i;j<=n+1; j+=i){
        v[j]=2;
        f=true;
    }
   }
   if(f) cout<<2<<endl;
   else cout<<1<<endl;
   for(long long i=2;i<=n+1;i++) cout<<v[i]<<" ";
   cout<<endl;
}