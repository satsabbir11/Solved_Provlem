#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"not divisible":"divisible")
#define loj(i,j) "Case "<<i<<": "<<j


int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    for(long long i=1;i<=t;i++){
        string s;
        long long m;
        cin>>s>>m;

        long long sz = s.size(), ans=0;

        for(long long i=0;i<sz;i++){
            if(s[i]=='-') continue;
            ans += s[i]-'0';
            ans%=m;
            ans*=10;
        }

        bool f = ans;
        cout<<loj(i, con)<<endl;
    }
}