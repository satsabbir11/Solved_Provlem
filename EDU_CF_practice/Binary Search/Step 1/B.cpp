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
 
   long long n,k,i;
   cin>>n>>k;
   long long a[n+2];
   for(i=1; i<=n;i++) cin>>a[i];
   a[n+1]=MOD;
    for(i=1;i<=k;i++)
    {
      long long x;
      cin>>x;
      long long l=1, h=n+1,mid;
      while(l<=h)
      {
        mid=(l+h)/2;
        if(x<a[mid] && l==h)
        {
          break;
        }
        if(x<a[mid]) h=mid;
        else if(x>=a[mid]) l=mid+1;
        //cout<<l<<" "<<h<<" "<<mid<<endl;
      }
      cout<<mid-1<<endl;
    }
}
