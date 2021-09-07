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

bool ispalin(string s, long long n)
{
  for(int i=0;i<=n/2;i++)
  {
    if(s[i]!=s[n-i-1]) return false;
  }
  return true;
}
 
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
    long long n,i,c0=0,c1=0;
    cin>>n;
    string s;
    cin>>s;
    for(i=0;i<n;i++)
    {
      if(s[i]=='0') c0++;
    }
    bool f=ispalin(s,n);
    if(f)
    {
      if(c0%2 && c0!=1) cout<<"ALICE"<<endl;
      else cout<<"BOB"<<endl;
    }
    else
    {
      if(c0==2 && n%2 && s[n/2]=='0') cout<<"DRAW"<<endl;
      else cout<<"ALICE"<<endl;
    }
   }
}