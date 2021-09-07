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
 
long long bit(long long n)
{
  long long c=0;
  while(n)
  {
    c++;
    n>>=1;
  }
  return c;
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
    if(c0%2 && c0!=1) cout<<"ALICE"<<endl;
    else cout<<"BOB"<<endl;
   }
}

// first we see for the even number of zero...there is always who take first move will lose by two pont like AAAB or AAAABB.
// so Alice lose for this condition.

// same for the odd number of zero Alice move first. then Bob move fist so Bob lose to Alice by one point. BBBA A . BBBBAA A