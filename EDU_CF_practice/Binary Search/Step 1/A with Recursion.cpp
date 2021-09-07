//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")
#define inf 100002
#define MOD 1000000007
 
bool isHere(long long n,long long a[],long long d, long long u, long long m)
{
  if(d>u) return false;
  long long mid=(d+u)/2;
  if(a[mid]<m) return isHere(n,a,mid+1, u, m);
  else if(a[mid]>m) return isHere(n,a,d, mid-1, m);
  return true;
}
 
 
int main()
{
    FastRead;
  
   // #ifndef sabbir
   //  freopen("input.txt", "r", stdin); 
   //  freopen("output.txt", "w", stdout);
   //  #endif
 
  long long k,i,n;
  cin>>n>>k;
  long long a[n+2];
  for(i=1;i<=n;i++) cin>>a[i];
  while(k--)
  {
    long long m;
    cin>>m;
    bool f=isHere(n,a,1,n,m);
    cout<<con<<endl;
  }
}