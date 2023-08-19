#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   int l = 1, r= 1e6;

   while (l<r)
   {
    int mid = (r+l)/2;
    cout<<mid<<endl<<flush;

    string s;
    cin>>s;
    if(s[0]=='>') l = mid+1;
    else r = mid-1;

   }
   cout<<"! "<<l<<endl<<flush;   
}