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
 
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define max5(a,b,c,d,e) max(max4(a,b,c,d),e)
#define min5(a,b,c,d,e) min(min4(a,b,c,d),e)
 
#define sortt(s) sort(s.begin(), s.end())
#define reversee(s) reverse(s.begin(), s.end())
#define reversesortt(s) sortt(s); reversee(s)
#define pb push_back
#define loj(i,j) "Case "<<i<<": "<<j
#define gap " "
 
// for (auto& x : a) cin >> x;
 
long long xOR(long long n)
{
  if (n % 4 == 0)
    return n;
 
  if (n % 4 == 1)
    return 1;
 
  if (n % 4 == 2)
    return n + 1;
 
  return 0;
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
    long long a,b,n,i;
    cin>>a>>b;
 
    n=xOR(a-1);
    //cout<<n<<gap;
        if((n^b)==a)
        {
            cout<<a+2<<endl;
            continue;
        }
    if(n==b) cout<<a<<endl;
    else cout<<a+1<<endl;
    //cout<<n<<endl;
 
   }
}
