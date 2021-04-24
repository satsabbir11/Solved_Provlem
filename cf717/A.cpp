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
  
//    #ifndef sabbir
//     freopen("/CP_OJ/input.txt", "r", stdin); 
//     freopen("/CP_OJ/output.txt", "w", stdout);
//     #endif

    long long t;
    cin>>t;
    while(t--)
    {
        long long n,k,i;
        cin>>n>>k;
        long long a[n+2];
        for(i=1;i<=n;i++) cin>>a[i];
        for(i=1;i<n;i++)
        {
            if(k>=a[i])
            {
                k-=a[i];
                a[n]+=a[i];
                a[i]=0;
            }
            else
            {
                a[i]-=k;
                a[n]+=k;
                k=0;
            }
        }
        for(i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
   
}