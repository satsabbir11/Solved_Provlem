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
 
   long long n,i,did;
   cin>>n;
   long long a[n+2];
   for(i=1;i<=n;i++) cin>>a[i];
   sort(a+1, a+n+1);
   long long k;
   cin>>k;
   for(i=1;i<=k;i++)
   {
    long long x,y;
    cin>>x>>y;
    a[0]=-MOD;
    long long l=0,h=n,mid;
    while(l<=h)
    {
      mid=(h+l+1)/2;
      if(x>a[mid] && h==l) break;
      if(x<=a[mid]) h=mid-1;
      else if(x>a[mid]) l=mid;
    }
    x=mid+1;
    a[n+1]=MOD;
    l=1;
    h=n+1;
    while(l<=h)
    {
      mid=(h+l)/2; 
      if(y>=a[mid]) l=mid+1;
      else h=mid;
    }
    y=mid-1;
    cout<<y-x+1<<" ";
   }
}