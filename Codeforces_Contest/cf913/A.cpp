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

        for(int i=1;i<=8;i++){
            if((s[1]-'0')!=i) cout<<s[0]<<i<<endl;
        }

        int cnt = s[1]-'0';

        for(char i='a';i<='h';i++){
            if((s[0])!=i) cout<<i<<cnt<<endl;
        }
    }
}