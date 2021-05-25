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
  for(i=1;i<=n;i++) cin>>a[i];
  while(k--)
  {
    long long m;
    cin>>m;
    long long d=1, u=n;
    bool f=false;
    while(d<=u && !f)
    {
      long long mid=(d+u)/2;
      if(a[mid]<m) d=mid+1;
      else if(a[mid]>m) u=mid-1;
      else f=true;
    }
    cout<<con<<endl;
  }
}