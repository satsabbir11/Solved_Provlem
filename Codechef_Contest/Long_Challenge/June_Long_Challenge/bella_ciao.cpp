//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")
#define inf 10002
#define MOD 1000000002
 
 
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
      long long D,d,p,q,ans=0,i,r,n;
      cin>>D>>d>>p>>q;
      n=D/d;
      r=D%d;
      if(n%2)
      {
        long long f=(n*(n-1)*q)/2;
        f+=(n*p);
        f*=d;
        ans+=f;
        ans+=(r*(p+(n*q)));
      }
      else
      {
        long long f=(2ll*p)+(n-1)*q;
        f*=(n/2);
        f*=d;
        ans+=f;
        ans+=(r*(p+(n*q)));
      }
      cout<<ans<<endl;
    }
}