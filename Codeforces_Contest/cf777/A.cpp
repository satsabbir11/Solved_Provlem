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
    long long n,ans=0;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        continue;
    }
    if(n==2){
        cout<<2<<endl;
        continue;
    }
    if(n%2){
        if(n%3==2){
            for(long long i=1;i<=n;i++){
            if(i%2){
                cout<<2;
                ans+=2;
            }
            else{
                cout<<1;
                ans++;
            }
            if(ans==n) break;
        }
        }
        else if(n%3==1){
            for(long long i=1;i<=n;i++){
            if(i%2==0){
                cout<<2;
                ans+=2;
            }
            else{
                cout<<1;
                ans++;
            }
            if(ans==n) break;
        }
        }
        else{
            for(long long i=1;i<=n;i++){
            if(i%2==1){
                cout<<2;
                ans+=2;
            }
            else{
                cout<<1;
                ans++;
            }
            if(ans==n) break;
        }
        }
    }
    else{
        if(n%3==2){
            for(long long i=1;i<=n;i++){
            if(i%2==1){
                cout<<2;
                ans+=2;
            }
            else{
                cout<<1;
                ans++;
            }
            if(ans==n) break;
        }
        }
        else if(n%3==1){
            for(long long i=1;i<=n;i++){
            if(i%2==0){
                cout<<2;
                ans+=2;
            }
            else{
                cout<<1;
                ans++;
            }
            if(ans==n) break;
        }
        }
        else{
            for(long long i=1;i<=n;i++){
            if(i%2){
                cout<<2;
                ans+=2;
            }
            else{
                cout<<1;
                ans++;
            }
            if(ans==n) break;
        }
        }
    }
    cout<<endl;
  }
}