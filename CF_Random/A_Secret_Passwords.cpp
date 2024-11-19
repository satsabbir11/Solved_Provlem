#include <bits/stdc++.h>
using namespace std;

vector<int>g[26];
vector<bool>vis(26, false), mp(26, false);

void dfs(int u){
    vis[u]=true;
    for(int v: g[u]){
        if(!vis[v]) dfs(v);
    }
}


int main(){
    int n; cin>>n;

    for(int i=1; i<=n; i++){
        string s; cin>>s;

        int x = s[0]-'a';
        mp[x]=true;
        
        for(int j=1; j<s.size(); j++){
            int y = s[j]-'a';
            mp[y]=true;
            g[x].push_back(y);
            // g[y].push_back(x);
        }
    }

    int cnt =0;

    for(int i=0; i<26; i++){
        if(!vis[i] and mp[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
}