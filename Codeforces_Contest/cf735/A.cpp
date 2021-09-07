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
    long long n;
    cin>>n;
    if(n==1)
      {
        cout<<1<<" "<<0<<endl;
        continue;
      }
    if(n%3==1)
    {
      long long m=(n-2)/3;
      long long g=(n-m)/2;
      g=n-g;
        cout<<(n-m)/2<<" "<<g/2<<endl;
    }
    else if(n%3==2)
      {
         long long m=(n-2)/3;
      long long g=(n-m)/2;
      g=n-g;
        cout<<g/2<<" "<<(n-m)/2<<endl;
      }
    else cout<<n/3<<" "<<n/3<<endl;
   }
}