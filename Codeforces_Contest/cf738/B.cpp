//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000005
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")

#define sortt(s) sort(s.begin(), s.end())
#define reversee(s) reverse(s.begin(), s.end())
#define reversesortt(s) sortt(s); reversee(s)
#define pb push_back
#define loj(i,j) "Case "<<i<<": "<<j

// for (auto& x : a) cin >> x;


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
    long long n,m1=-1,i;
    cin>>n;
    string s;
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(s[i]!='?')
        {
            m1=i;
            break;
        }
    }
    
    for(i=m1+1;i<n;i++)
    {
        if(s[i-1]=='B' && s[i]=='?' && i>0) s[i]='R';
        else if(s[i-1]=='R' && s[i]=='?' && i>0) s[i]='B';
    }
    for(i=m1-1;i>=0;i--)
    {
        if(s[i+1]=='B' && s[i]=='?' && i<n-1) s[i]='R';
        else if(s[i+1]=='R' && s[i]=='?' && i<n-1) s[i]='B';
    }
    if(m1==-1)
    {
        for(i=0;i<n;i++)
        {
            if(i%2) s[i]='B';
            else s[i]='R';
        }
    }
    cout<<s<<endl;
   }
}