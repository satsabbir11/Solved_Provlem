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
      long long a,b,n,i;
      cin>>a>>b;
      n=a+b;
      string s;
      cin>>s;
      for(i=0;i<n;i++)
      {
        if(s[i]=='0') a--;
        else if(s[i]=='1') b--;
      }
      bool f=true;
 
      for(i=0;i<n/2 && f;i++)
      {
        if(s[i]=='?' && s[n-i-1]!='?')
        {
            s[i]=s[n-i-1];
            if(s[n-i-1]=='0') a--;
            else b--;
        }
        else if(s[i]!='?' && s[n-i-1]=='?')
        {
            s[n-i-1]=s[i];
            if(s[i]=='0') a--;
            else b--;
        }
        if(a<0 || b<0) f=false;
      }
     if(f)
     {
         for(i=0;i<n/2 && f;i++)
      {
        if(s[i]=='?' && s[n-i-1]=='?')
        {
            if(a>=b)
            {
                s[i]='0';
                a--;
                s[n-1-i]='0';
                a--;
            }
            else
                {
                s[i]='1';
                b--;
                s[n-1-i]='1';
                b--;
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(s[i]=='?')
        {
            if(a>0)
                {
                    s[i]='0';
                    a--;
                }
            else if(b>0)
                {
                    s[i]='1';
                    b--;
                }
        }
    }
    if(a<0 || b<0) f=false;
     }
 
 
     for(i=0;i<n/2 && f;i++)
      {
        if(s[i]!=s[n-i-1]) f=false;
    }
     if(f) cout<<s<<endl;
     else cout<<-1<<endl;
 
    }
   
}