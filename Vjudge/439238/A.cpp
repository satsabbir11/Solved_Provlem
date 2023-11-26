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

    string s;
    cin>>s;
    long long i,j,k,n,ans=0;
    n=s.length();
    for(i=0;i<n-2;i++)
    {
       for(j=i+1;j<n-1;j++)
       {
           for(k=j+1;k<n;k++)
           {
               if(s[i]=='Q' && s[j]=='A' && s[k]=='Q') ans++;
           }
       }
    }
    cout<<ans<<endl;
}