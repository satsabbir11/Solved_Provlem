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
        long long n,i,sum=0,mem;
        cin>>n;
        long long b[n+4];
        for(i=1;i<=n+2;i++) cin>>b[i];
        sort(b+1,b+n+3);
        for(i=1;i<=n+1;i++) sum+=b[i];
        bool f=false;
        for(i=1;i<=n+1;i++)
        {
        if(sum-b[i]==b[n+2])
        {
        mem=i;
        f=true;
        }
        }
            if(f)
            {
                for(i=1;i<=n+1;i++)
            {
                if(mem!=i) cout<<b[i]<<" ";
            }
            cout<<endl;
            continue;
            }
            else
            {
                if(b[n+1]*2==sum)
                {
                    for(i=1;i<=n;i++) cout<<b[i]<<" ";
                        cout<<endl;
                    continue;
                }
            }
            cout<<-1<<endl;
    }
}