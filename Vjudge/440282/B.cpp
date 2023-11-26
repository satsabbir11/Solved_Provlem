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
    long long n,i,c0=-1,c1=-1;
    cin>>n;
    string s;
    cin>>s;
    for(i=0;i<n;i++)
    {
      if(s[i]=='1')
      {
        c0=i+1;
        break;
      }
    }
    for(i=n-1;i>=0;i--)
    {
      if(s[i]=='1')
      {
        c1=i+1;
        break;
      }
    }
    long long mx=max(n-c0+1,c1);
    if(c0!=-1) cout<<max(n,mx*2)<<endl;
    else cout<<n<<endl;
   }
}