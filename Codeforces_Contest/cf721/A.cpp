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
 
long long bit(long long n)
{
  long long c=0;
  while(n)
  {
    c++;
    n>>=1;
  }
  return c;
}
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
    long long n,ans=1;
    cin>>n;
    long long b=bit(n);
    b--;
    for(long long i=1;i<=b;i++) ans*=2;
      cout<<ans-1<<endl;
   }
}

// to inactive the last bit of n you need its highst lower bit number like 1,111,1111,11111