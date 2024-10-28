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
        long long n, k;
        cin>>n>>k;

        string s; cin>>s;


        long long here = -1;

        for(int i=n-k-1; i>=0; i--){
            if(i>=k-1){
                here = i; break;
            }
        }

        long long cnt=0;

        for(char x: s) cnt+=(x=='1');

        long long fnt =0;

        cout<<max(cnt, here+1)<<endl;
    }
}