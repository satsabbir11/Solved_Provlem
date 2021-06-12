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
    long long n,i,l,r,j,cnt=0,ans=0,ans1=0;
    cin>>n>>l>>r;
    long long a[n+2];
    for(i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    
    for(i=1;i<=n;i++)
    {
      long long x=r-a[i],lo=1,up=n+1,mid;
      a[n+1]=MOD;
 
      while(lo<=up)
      {
        mid=(lo+up)/2;
        if(x<a[mid] && lo==up) break;
        if(x<a[mid]) up=mid;
        else if(a[mid]<=x) lo=mid+1; 
      }
      //cout<<endl;
      ans+=(mid-1);
      if(i<=mid-1) ans--;
    //}
    //cout<<ans<<endl;
  }
  for(i=1;i<=n;i++)
    {
      long long x=l-1-a[i],lo=1,up=n+1,mid;
      a[n+1]=MOD;
 
      while(lo<=up)
      {
        mid=(lo+up)/2;
        if(x<a[mid] && lo==up) break;
        if(x<a[mid]) up=mid;
        else if(a[mid]<=x) lo=mid+1; 
      }
      //cout<<endl;
      ans1+=(mid-1);
      if(i<=mid-1) ans1--;
    //}
    //out<<ans<<endl;
  }
  cout<<(ans-ans1)/2<<endl;
   }
}