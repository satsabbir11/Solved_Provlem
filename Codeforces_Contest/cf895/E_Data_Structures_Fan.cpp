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
        long long n;
        cin>>n;
        
        long long a[n+2], pre[n+2];
        for(long long i=0;i<n;i++){
            cin>>a[i];
            pre[i+1] = pre[i]^a[i];
        }

        string s;
        cin>>s;

        long long zero =0, one =0;
         for(long long i=0;i<n;i++){
            if(s[i]=='0') zero^=a[i];
            else one ^=a[i];
        }

        int q;
        cin>>q;
        while(q--){
            int type;
            cin>>type;
            if(type==1){
                long long x, y;
                cin>>x>>y;
                int change = pre[x-1]^pre[y];
                zero^= change;
                one^=  change;
            }
            else{
                int g;
                cin>>g;
                if(g) cout<<one<<" ";
                else cout<<zero<<" ";
            }
        }
        cout<<endl;
    }
}