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
      long long n,i,j,in=1;
      cin>>n;
      if(n==1) cout<<1<<endl;
      else if(n==2) cout<<-1<<endl;
      else{
          for(i=1;i<=n;i++)
          {
              for(j=1;j<=n;j++)
              {
                  cout<<in<<" ";
                  in+=2;
                  if(in>n*n) in=2;
              }
              cout<<endl;
          }
      }
    }
}