#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;

      string s;
      cin>>s;

      bool f=false;
      string t= "2020";

      for(int i=0;i<=4;i++){
         if(s.substr(0,i) + s.substr(n-4+i,4-i)==t) f=true;
      }
      cout<<con<<endl;
   }
}