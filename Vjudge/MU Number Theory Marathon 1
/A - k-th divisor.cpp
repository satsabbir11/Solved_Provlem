#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   long long n,k;
   cin>>n>>k;


   vector<long long>v;

   for(long long i=1;i*i<=n;i++){
    if(n%i==0){
        v.push_back(i);
        if((n/i)!=i) v.push_back(n/i);
    }
   }
   sort(v.begin(), v.end());
   if(v.size()<k) cout<<-1<<endl;
   else cout<<v[k-1]<<endl;

}