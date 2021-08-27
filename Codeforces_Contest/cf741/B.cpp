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
    long long n,m=0,k=-1,i,r=0,j;
    string s;
    cin>>n>>s;
    for(i=0;i<n;i++)
    {
        long long g=s[i]-'0';
        if((g%2==0 && g!=2) || (g%3==0 && g!=3) || g==1) {k=g; m=1; break;}
    }
    bool f=false;
    if(!m)
    {
        for(i=0;i<n;i++)
        {
            long long g=s[i]-'0';
            
            if(g==2 || g==5 || g==7)
            {
                for(j=i+1;j<n;j++)
                {
                    long long p=s[j]-'0';
                    if(p==2 || p==7 || p==5) { f=true; r=g*10+p; break; }
                }
                if(f) break;
            }
            else if(g==3)
            {
                for(j=i+1;j<n;j++)
                {
                    long long p=s[j]-'0';
                    if(p==3 || p==2 || p==5) { f=true; r=g*10+p; break; }
                }
                if(f) break;
            }
        }
    }
 
    if(m) cout<<1<<endl<<k<<endl;
    else
    {
        if(f) cout<<2<<endl<<r<<endl;
        else cout<<1<<endl<<1<<endl;
    }
   }
}