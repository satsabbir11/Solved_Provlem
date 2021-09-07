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
  // #ifndef sabbir
  //   freopen("input.txt", "r", stdin); 
  //   freopen("output.txt", "w", stdout);
  //   #endif

    long long t;
    cin>>t;
    while(t--)
    {
      long long n,m,i,j;
      cin>>n>>m;
      long long a[n+2][m+2], b[n+2][m+2];
      memset(b,0,sizeof(b));
      vector<pair<long long, long long>>p;
      for(i=0;i<n;i++)
      {
        for(j=0;j<m;j++)
        {
          cin>>a[i][j];
          p.push_back({a[i][j],i});
        }
      }
      sort(p.begin(),p.end());
      for(i=0;i<m;i++) b[p[i].second][i]=p[i].first;
      for(j=i;j<n*m;j++)
      {
        long long k=p[j].second;
        for(i=0;i<m;i++)
        {
          if(!b[k][i])
          {
            b[k][i]=p[j].first;
            break;
          }
        }
      }
      for(i=0;i<n;i++)
      {
        for(j=0;j<m;j++) cout<<b[i][j]<<" ";
          cout<<endl;
      }
    }
}