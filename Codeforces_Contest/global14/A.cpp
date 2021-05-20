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
 
   long long t;
   cin>>t;
   while(t--)
   {
    long long n,x,i;
    cin>>n>>x;
    long long a[n+2],sum=0,r=0,mem=0;
    vector<long long>p;
    for(i=1;i<=n;i++)
    {
      cin>>a[i];
      r+=a[i];
    }
    sort(a+1,a+1+n);
 
    for(i=1;i<=n;i++)
    {
      sum+=a[i];
      if(sum!=x) p.push_back(a[i]);
      else
      {
        mem=a[i];
        sum-=a[i];
      }
    }
 
    if(mem) p.push_back(mem);
    if(r==x) cout<<"NO"<<endl;
    else
    {
      cout<<"YES"<<endl;
      long long l=p.size();
      for(i=0;i<l;i++) cout<<p[i]<<" ";
        cout<<endl;
    }
   }
}