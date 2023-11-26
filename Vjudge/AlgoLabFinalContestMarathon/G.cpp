#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   int n;
   cin>>n;

   if(n>2) cout<<n-2<<endl;
   else cout<<n+2<<endl;
}