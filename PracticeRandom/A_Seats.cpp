#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);


        long long n, cnt=0;
        string s;
        cin>>n>>s;
        

        for(long long i=1;i<n;i++){
            if(s[i]=='.' and s[i-1]==s[i+1] and s[i+1]=='#') cnt++;
        }

        cout<<cnt<<endl;
    
}