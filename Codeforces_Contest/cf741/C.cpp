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
#define gap " "

// for (auto& x : a) cin >> x;

void binary(long long n, string s)
{
    long long i;
    for(i=0;i<n;i++)
      {
          if(s[i]=='0')
          {
            if(i>=(n/2)) cout<<1<<gap<<i+1<<gap<<1<<gap<<i<<endl;
            else cout<<i+1<<gap<<n<<gap<<i+2<<gap<<n<<endl;
            return;
          }
      }
      cout<<1<<gap<<n-1<<gap<<2<<gap<<n<<endl;
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
      long long n,i;
      string s;
      cin>>n>>s;
      binary(n,s);
    }
}