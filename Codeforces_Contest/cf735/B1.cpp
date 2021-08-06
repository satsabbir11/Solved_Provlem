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
  
   // #ifndef sabbir
   //  freopen("input.txt", "r", stdin); 
   //  freopen("output.txt", "w", stdout);
   //  #endif
 
   long long t;
   cin>>t;
   while(t--)
   {
    string s;
    cin>>s;
    long long i,l=s.size(),d[1000]={},cnt=0,fnt=0;
    for(i=0;i<l;i++)
    {
      long long m=s[i]-'a'+1;
      d[m]++;
    }
    for(i=0;i<l;i++)
    {
      long long m=s[i]-'a'+1;
      if(d[m]>=2) cnt++;
      else if(d[m]==1) fnt++;
      d[m]=0;
    }
    cout<<fnt/2+cnt<<endl;
   }
}