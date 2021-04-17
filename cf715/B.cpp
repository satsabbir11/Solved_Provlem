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
    long long n,i,cnt=0, fnt=0, lnt=0;
    cin>>n;
    string s;
    cin>>s;
    bool f=true;
    for(i=0;i<n && f;i++) 
    {
 
      if(s[i]=='T') cnt++;
      else if(s[i]=='M')
      {
        fnt++;
        cnt--;
        if(cnt<0) f=false;
      }
    }
 
 
 
     for(i=n-1;i>=0 && f;i--) 
    {
 
      if(s[i]=='T') lnt++;
      else if(s[i]=='M')
      {
        lnt--;
        if(lnt<0) f=false;
      }
    }
 
    if(f && cnt==fnt && fnt==lnt) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
   }
}