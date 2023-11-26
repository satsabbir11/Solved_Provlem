//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ

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

   long long t;
   cin>>t;
   while(t--)
   {
    long long a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    long long x=(a+c-1)/c;
    long long y=(b+d-1)/d;
    if(x+y<=k) cout<<x<<" "<<y<<endl;
    else cout<<-1<<endl;
   }
}