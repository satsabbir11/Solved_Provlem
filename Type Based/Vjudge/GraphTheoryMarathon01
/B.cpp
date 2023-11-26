#include <bits/stdc++.h>
using namespace std;


void dfs(char u, vector<vector<char>>&p, vector<bool>&vis, int dis){
    for(char i =0; i<p[u].size(); i++){
        char v = p[u][i];
        if(!vis[v]){
            vis[v]=true;
            dfs(v, p, vis, dis+1);
        }
    }
}

int main(){
    int t;
    char c;
    string s;

    cin>>t;
    while(t--){
        int cnt =0;
        cin>>c;
        int n = c-'A';
        getline(cin,s);
           
        vector<vector<char>>p(100, vector<char>());
        vector<bool>vis(100, false);


        while(getline(cin,s)){
            if(s.empty()) break;
            //cout<<s<<endl;
            p[s[0]].push_back(s[1]);
            p[s[1]].push_back(s[0]);
        }


        for(char i='A';i<=c;i++){
            if(!vis[i]){
                cnt++;
                vis[i] = true;
                dfs(i, p, vis, 0);
            }
        }
        cout<<cnt<<endl;
        if(t) cout<<endl;
    }
}