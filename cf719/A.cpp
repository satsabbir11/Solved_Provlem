// سْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ

#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long
#define con (f?"YES":"NO")
#define inf 10002
#define MOD 1000000007

int main()
{
    FastRead;

    // #ifndef sabbir
    // freopen("/CP_OJ/input.txt", "r", stdin);
    // freopen("/CP_OJ/output.txt", "w", stdout);
    // #endif

    long long t;
    cin>>t;
    while(t--)
    {
      long long n;
      cin>>n;
      string s;
      cin>>s;
      map<long long, long long>d;
      bool f=true;
      for(long long i=0;i<n;i++)
      {
          long long x=s[i],y;
          if(i!=0) y=s[i-1];
          d[x]++;
          if(d[x]>=2 && y!=x && i!=0)
          {
              f=false;
              //cout<<i<<endl;
              break;
          }
      }
      cout<<con<<endl;
    }
}