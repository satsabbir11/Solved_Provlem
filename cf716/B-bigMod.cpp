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

long long bigMOD(long long n, long long k)
{
  if(!k) return 1;
  else if(k%2) return ((n%MOD)*(bigMOD(n,k-1))%MOD)%MOD;
  else
  {
    long long rem=(bigMOD(n,k/2))%MOD;
    return (rem*rem)%MOD;
  }
}


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
    long long n,k,i,ans=1;
    cin>>n>>k;
    cout<<bigMOD(n,k)<<endl;
   }
}