#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long a, cnt =0, ans, tem=0;
    while(cin>>a){
        if(a==0){
            cnt=0;
            if(tem==a) break;
            cout<<ans<<endl;
            tem=0;
            continue;
        }
        if(cnt<=1) ans = abs(tem-a);
        else ans = __gcd(ans, abs(tem-a));
        tem = a;
        cnt++;
    }
}