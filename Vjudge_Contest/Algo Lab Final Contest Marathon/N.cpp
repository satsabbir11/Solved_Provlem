#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);


   int n;
   cin>>n;

   pair<int, int>p[n+2];
   for(int i=0;i<n;i++){
    cin>>p[i].first;
    p[i].second = i+1;
   }

   sort(p, p+n);

   for(int i=0;i<n/2;i++){
    cout<<p[i].second<<" "<<p[n-i-1].second<<endl;
   }
}