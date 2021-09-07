#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")
#define inf 10002


int main()
{
    FastRead;
  
   // #ifndef sabbir
   //  freopen("input.txt", "r", stdin); 
   //  freopen("output.txt", "w", stdout);
   //  #endif

   long long t;
   cin>>t;
   for(long long i=1;i<=t;i++)
   {
    long long n, root, row, col, cls;
       cin>>n;
   long long sq=sqrt(n);

   long long x=sq*sq;
   if(x<n) sq++; 

   long long a=abs((sq*sq)-n);
   long long b=abs((sq-1)*(sq-1)-n);
   if(a<b) cls=sq*sq;
   else cls=(sq-1)*(sq-1);
   if(cls%2==1)
   {
    row=sq;
     if(n<cls) col=cls-n+1;
    else if(n>cls) col=n-cls;
    else col=1;
   }
   else
   {
    col=sq;
    if(n<cls) row=cls-n+1;
    else if(n>cls) row=n-cls;
    else row=1;
   }
   cout<<"Case "<<i<<": "<<col<<" "<<row<<endl;
  }
}