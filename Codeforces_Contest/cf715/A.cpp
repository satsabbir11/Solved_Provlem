#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long
 
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
   while(t--)
   {
    long long n,i,b,l=1;
    cin>>n;
    long long a[n+2];
    for(i=1;i<=n;i++)
    {
      cin>>b;
      if(b%2==0)
        {
          a[l]=b;
          l++;
        }
        else cout<<b<<" ";
    }
    for(i=1;i<l;i++) cout<<a[i]<<" ";
      cout<<endl;
   }
}