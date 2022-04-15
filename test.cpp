//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000010
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")

#define CLR(a) memset(a, -1, sizeof(a))
#define CLN(a) memset(a, 0, sizeof(a))
 
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

struct Line
{
    long long w,in,val;
};


int main(){
  long long t;
  cin>>t;
  while(t--){
    long long n,m,mx=0;
    cin>>n>>m;
    vector<Line>a(m);
    for(long long i=0; i<m;i++) {cin>>a[i].in>>a[i].w; a[i].val=i;}
    
    sort(a.begin(),a.end(),[](Line i, Line j){
        return i.w<j.w;
    });
    for(long long i=0; i<m;i++) {if(i>=2*n){a.pop_back();} else {mx+=a[i].w;}}
    cout<<mx<<endl;
    sort(a.begin(),a.end(),[](Line i, Line j){
        return i.in<j.in;
    });
    for(long long i=0; i<n;i++) cout<<a[i].val<<" "<<a[2*n-i-1].val<<endl;
  }
}