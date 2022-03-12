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


int main(){
  long long t;
  cin>>t;
  while(t--){
    long long n;
    cin>>n;
    long long in,tt=n;
    long long a[n+2];
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==n) in=i;
    }
    //cout<<in<<endl;
    //continue;
    vector<long long>p;
    long long cur=n;
    while(1){
        long long f=in%cur;
        p.push_back(f);
        
        if(cur==1) break;
        //cout<<cur<<endl;
        long long gg,b[cur+2],k=1;
        for(long long i=in+1;i<=cur;i++) b[k++]=a[i];
        for(long long i=1;i<=in;i++) b[k++]=a[i];
        //cout<<gg<<endl;
        //in=gg;
            for(long long i=1;i<=cur;i++){
                if(b[i]==(cur-1)) in=i;
                a[i]=b[i];
            }
        //for(long long i=1;i<=n;i++) cout<<a[i]<<" ";
        cur--;
        //cout<<endl;
    }
    for(long long i=n-1;i>=0;i--) cout<<p[i]<<" ";
    cout<<endl;
  }
}