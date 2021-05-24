//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")
#define inf 10005
#define MOD 1000000007


int main()
{
    FastRead;
  
   // #ifndef sabbir
   //  freopen("input.txt", "r", stdin); 
   //  freopen("output.txt", "w", stdout);
   //  #endif

    long long n,m,k,i;
    cin>>n>>m>>k;

    long long a[n+2]={},c[m+2]={},d[m+2]={},f[n+2]={};
    pair<long long, long long>b[m+2];

    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=m;i++)
    {
      long long x,y,z;
      cin>>x>>y>>z;
      b[i].first=x;
      b[i].second=y;
      d[i]=z;
    }
    for(i=1;i<=k;i++)
    {
      long long x,y;
      cin>>x>>y;
      c[x]++;
      c[y+1]--;
    }
    for(i=1;i<=m;i++) c[i]+=c[i-1];
    for(i=1;i<=m;i++) d[i]*=c[i];
    for(i=1;i<=m;i++)
    {
      f[b[i].first]+=d[i];
      f[b[i].second+1]-=d[i];
    }
    for(i=1;i<=n;i++)
      {
        f[i]+=f[i-1];
        cout<<a[i]+f[i]<<" ";
      }
      cout<<endl;
}