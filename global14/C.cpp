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
        cout<<"YES"<<endl;
      long long n,m,x,i;
      cin>>n>>m>>x;
      set<pair<long long, long long>>s;
      for(i=1;i<=m;i++) s.insert({0,i});
      for(i=1;i<=n;i++)
      {
          long long h;
          cin>>h;
          pair<long long, long long>p=*s.begin();
          cout<<p.second<<" ";
          s.erase(p);
          s.insert({p.first+h, p.second});
      }
      cout<<endl;
    }
}