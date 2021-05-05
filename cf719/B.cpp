// سْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
#include<bits/stdc++.h>
using namespace std;
 
#define pi acos(-1)
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long
#define con (f?"YES":"NO")
#define inf 10002
#define MOD 1000000007
long long digit(long long n)
{
    long long cnt=0;
    while(n!=0)
    {
        n/=10;
        cnt++;
    }
    return cnt;
}
 
long long fnum(long long n, long long dig)
{
  vector<long long>p;
  while(n!=0)
  {
    p.push_back(n%10);
    n/=10;
  }
  long long i,f=p[dig-1];
  for(i=dig-2;i>=0;i--)
  {
    if(p[i]>f) return f;
    else if(p[i]<f) return f-1;
  }
  return f;
}
 
 
int main()
{
    FastRead;
 
    // #ifndef sabbir
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    // #endif
 
    long long t;
    cin>>t;
    while(t--)
    {
      long long n,i,ans=0,dig,first;
      cin>>n;
      dig=digit(n);
      first=fnum(n,dig);
      ans=(dig-1)*9;
      ans+=first;
      cout<<ans<<endl;
    }
}