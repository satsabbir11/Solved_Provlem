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
        string s;
        cin>>s;
        long long n = s.size(), pos;
        cin>>pos;

        long long step, ind;
        pos--;

        for(long long i=0; i<n;i++){
            long long len = n-i;
            if(pos<len){
                step=i;
                ind = pos;
                break;
            }
            pos-=len;
        }

        string ans;
        for(char c: s){
            while(step && !ans.empty() && ans.back()>c){
                step--;
                ans.pop_back();
            }
            ans+=c;
        }

        cout<<ans[ind];
    }
}
