//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ

//https://codeforces.com/contest/1539/problem/A

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")
#define inf 10002
#define MOD 1000000007


int main()
{
    FastRead;
  
   // #ifndef sabbir
   //  freopen("input.txt", "r", stdin); 
   //  freopen("output.txt", "w", stdout);
   //  #endif

   long long k;
   cin>>k;
   while(k--)
   {
    long long n, x,t, d;
    cin>>n>>x>>t;
    d=t/x;
    if(d>=n) cout<<n*(n-1)/2<<endl;
    else cout<<(d*(d-1)/2)+((n-d)*d)<<endl;
   }
}