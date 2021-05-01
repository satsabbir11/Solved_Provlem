//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long
#define For(s,n) for(long long i=s;i<=n;i++)
 
int main()
{
  FastRead;
  
    // #ifndef sabbir
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    // #endif
 
  long long n,m;
  cin>>n>>m;
    long long i,a[n+2],cum[n+2]={},ans[n+2]={};
    for(i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++) cum[i]=cum[i-1]+a[i];
    for(i=1;i<=n;i++)
    {
      ans[i]=cum[i]+ans[max(0ll,i-m)];
      cout<<ans[i]<<" ";
    }
}

//one of the best