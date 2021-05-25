//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long
#define con (d[m]?"YES":"NO")
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
  long long a;
  map<long long,long long>d;
  for(i=1;i<=n;i++)
    {
      cin>>a;
      d[a]=true;
    }
  while(k--)
  {
    long long m;
    cin>>m;
    cout<<con<<endl;
  }
}