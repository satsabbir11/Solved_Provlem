#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long

#define MOD 1000000007;


int main()
{
    FastRead;
  
   // #ifndef sabbir
   //  freopen("input.txt", "r", stdin); 
   //  freopen("output.txt", "w", stdout);
   //  #endif

   long long t, d[200017],i;
   cin>>t;
   for(i=0;i<=9;i++) d[i]=1;
    for(i=10;i<=200015;i++) d[i]=(d[i-9]+d[i-10])%MOD;
   while(t--)
   {
    long long n,ans=0,i,k;
    cin>>n>>k;
    while(n>0)
    {
      ans=(ans+d[(n%10)+k])%MOD;
      n/=10;
    }
    cout<<ans<<endl;
   }
}