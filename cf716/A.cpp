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
  
   #ifndef sabbir
    freopen("/CP_OJ/input.txt", "r", stdin); 
    freopen("/CP_OJ/output.txt", "w", stdout);
    #endif

    long long t;
    cin>>t;
    while(t--)
    {
        long long n,i,a;
        double cnt=1;
        cin>>n;
        bool f=false;
        for(i=1;i<=n;i++)
        {
            cin>>a;
            long long x=sqrt(a);
            if(x*x!=a) f=true;
        }
        cout<<con<<endl;
    }
   
}