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
    FastRead;
  
   // #ifndef sabbir
   //  freopen("input.txt", "r", stdin); 
   //  freopen("output.txt", "w", stdout);
   //  #endif

    long long n,i,j,x=0,y=0;
    cin>>n;
    long long a[n+2];
    for(i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(i=1;i<=n/2;i++) x+=a[i];
    for(j=i;j<=n;j++) y+=a[j];
    cout<<(y*y)+(x*x)<<endl;
  }