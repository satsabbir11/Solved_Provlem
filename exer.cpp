//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")
#define inf 10002


int main()
{
  FastRead;

//    #ifndef sabbir
//     freopen("/CP_OJ/input.txt", "r", stdin); 
//     freopen("/CP_OJ/output.txt", "w", stdout);
//     #endif

  long long t;
  cin>>t;
  while(t--)
  {
      long long n,i,j,l=0;
      vector<long long>p;
      cin>>n;
      for(i=n+1;;i++)
      {
          bool f=true;
          for(j=2;j*j<=i;j++)
          {
              if(i%j==0)
              {
                  f=false;
                  break;
              }
          }
          if(f)
          {
              p.push_back(i);
              l++;
              if(l==2) break;
              i+=(n-1);
          }
      }
      cout<<min(p[0]*p[1],p[0]*p[0]*p[0])<<endl;
  }
}