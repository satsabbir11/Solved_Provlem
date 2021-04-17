#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long
#define inf 2005

long long a[inf], d[inf][inf];

long long dp(long long l, long long r)
{
    if(d[l][r]!=-1) return d[l][r];
    if(l==r) return 0;
    return d[l][r]= a[r]-a[l]+min(dp(l,r-1),dp(l+1,r));
}


int main()
{
    FastRead;
  
//    #ifndef sabbir
//     freopen("/CP_OJ/input.txt", "r", stdin); 
//     freopen("/CP_OJ/output.txt", "w", stdout);
//     #endif

    long long n,i;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    sort(a+1, a+n+1);
    memset(d, -1, sizeof d);
    cout<<dp(1,n)<<endl;
}