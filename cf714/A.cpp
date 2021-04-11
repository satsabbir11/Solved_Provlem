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
  
    #ifndef sabbir
    freopen("/CP_OJ/input.txt", "r", stdin); 
    freopen("/CP_OJ/output.txt", "w", stdout);
    #endif
    
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,k,l,i;
        cin>>n>>k;
        if(n%2==0) l=n/2-1;
        else l=n/2;
        
        if(l>=k)
        {
            cout<<1<<" ";
            for(i=2;i<=n;i+=2)
            {
               if(k>0)
               {
                   if(n%2==0 && i==n) cout<<i<<" ";
                   else cout<<i+1<<" "<<i<<" ";
                   k--;
               }
               else
                {
                  if(n%2==0 && i==n) cout<<i<<" ";
                  else cout<<i<<" "<<i+1<<" ";
                }
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
}