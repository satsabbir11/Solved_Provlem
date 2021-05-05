// سْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ

#include<bits/stdc++.h>
using namespace std;

#define pi acos(-1)
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ull unsigned long long
#define con (f?"YES":"NO")
#define inf 10002
#define MOD 1000000007

int main()
{
    FastRead;

    // #ifndef sabbir
    // freopen("/CP_OJ/input.txt", "r", stdin);
    // freopen("/CP_OJ/output.txt", "w", stdout);
    // #endif

    long long t;
    cin>>t;
    while(t--)
    {
       long long n,l,r,i;
       cin>>n>>l>>r;
       map<long long, long long>left,right;
       long long a[n+2];
       for(i=1;i<=n;i++)
       {
           long long x;
           cin>>x;
           a[i]=x;
           if(i<=l) left[x]++;
           else right[x]++;
       }
       for(i=1;i<=n;i++)
       {
           long long mn=min(left[i],right[i]);
           left[i]-=mn;
           right[i]-=mn;
           l-=mn;
           r-=mn;
       }
       long long ans=0;
       if(l>r)
       {
           swap(left,right);
           swap(l,r);
       }
       for(i=1;i<=n;i++)
       {
           long long bz=right[i]/2,mn=r-l;
           ans+=((min(bz*2,mn))/2);
           r-=min(bz*2,mn);
       }
       cout<<ans+r<<endl;
    }
}