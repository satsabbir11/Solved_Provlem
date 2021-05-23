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
 
   long long n,m,ans=0,i,j;
   cin>>n>>m;
   long long a[n+2],b[n+2]={};
   for(i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
  for(i=1;i<=m;i++)
  {
    long long x,y;
    cin>>x>>y;
    b[x]++;
    b[y+1]--;
  }
  for(i=1;i<=n+1;i++) b[i]+=b[i-1];
  sort(b+1,b+1+n);
  for(i=n;i>=1;i--) ans+=(a[i]*b[i]);
    cout<<ans<<endl;
}