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
       int n =s.size();
       vector<int>v1, v2;
      for(int i=0;i<n;i++){
        char x = s[i];
        if(x=='b'){
            int cnt = v1.size();
            if(cnt) v1.pop_back();
            continue;
        }
        if(x=='B'){
            int cnt = v2.size();
            if(cnt) v2.pop_back();
            continue;
        }

        if(x>='a' && x<='z') v1.push_back(i);
        else v2.push_back(i);
       }

       set<int>ss;


       for(int x: v1) ss.insert(x);
       for(int x: v2) ss.insert(x);

       for(auto x: ss) cout<<s[x];
       cout<<endl;
    }
}