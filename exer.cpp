//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
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
     long long n,i;
     cin>>n;
     long long a[n+2];
     map<long long, long long>mp,np;
     for(i=1;i<n;i++)
     {
         mp[a[i]]++;
         if(mp[a[i]]==2)
             {
                 mp[a[i]+1]++;
                 mp[a[i]]=0;
             }
        vector<long long>p;
         for(j=i+1;j<=n;j++) p.push_back(a[j]);
         sort(p.begin(),p.end());
         for(j=1;j<=l;j++)
         {
             if(p[j]==p[j-1]) p[]
         }

     }
  }
}