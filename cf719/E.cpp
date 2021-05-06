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
      long long n,st=0,i;
      vector<long long>p;
      cin>>n;
      string s;
      cin>>s;
      for(i=0;i<n;i++)
      {
          if(s[i]=='*')
          {
              p.push_back(i);
              st++;
          }
      }
      //for(i=0;i<st;i++) cout<<p[i]<<" ";
      long long ans=inf,j=0;
      while(j+st<n)
      {
          long long r=j,cnt=0;
      for(i=0;i<st;i++)
      {
          cnt+=(abs(r-p[i]));
          r++;
      }
      ans=min(ans,cnt);
      j++;
      }
      cout<<(st==n?0:ans)<<endl;
    }
}