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
       long long n,i,m,d[1000]={},l;
       cin>>n;
       long long a[n+2];
       for(i=1;i<=n;i++)
       {
        cin>>a[i];
        d[a[i]]++;
       }
       for(i=1;i<n;i++)
       {
        if(a[i]!=a[i+1])
            {
                m=a[i];
                l=a[i+1];
                break;
            }
       }
       if(d[m]>d[l]) cout<<i+1<<endl;
       else cout<<i<<endl;
 
    }
   
}