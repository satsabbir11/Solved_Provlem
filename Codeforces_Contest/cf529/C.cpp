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

   long long n,k,cnt=0,fnt=0,mem;
   cin>>n>>k;
   long long i;
   bool f=true;
   queue<long long>q;
   for(i=31;i>=0;i--)
   {
    if(n&(1<<i))
      {
       q.push(1<<i);
        cnt++;
      }
   }
   if(cnt>k || n<k)
    {
      cout<<"NO"<<endl;
      return 0;
    }
    long long ans=cnt;
    while(ans!=k)
    {
      long long x=q.front();
     if(x==1)
     {
      q.pop();
      q.push(1);
     }
     else
     {
       q.pop();
      q.push(x/2);
      q.push(x/2);
      ans++;
     }
    }
    cout<<"YES"<<endl;
    while(!q.empty())
    {
      long long x=q.front();
      q.pop();
      cout<<x<<" ";
    }
    cout<<endl;

}