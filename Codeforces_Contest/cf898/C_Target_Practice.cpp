#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n=10, m=10, ans =0;
        char x;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m; j++){
                cin>>x;
                if(x=='X'){
                    long long x = i, y= j;
                    if(x>5) x= 11-x;
                    if(y>5) y= 11-y;
                    //cout<<x<<" "<<y<<endl;
                    ans+=min(x,y);
                }
            }
        }

        cout<<ans<<endl;
    }
}