#include <bits/stdc++.h>
using namespace std;

int minimumSize=200005;
int n;
int selfChar[200005];
vector<vector<int>>edges(200005);
vector<vector<int>>curNodeChar(200005, vector<int>(30));
int givenStringCharCount[200005], sizeOfNode[200005];

void dfs(int u, int par){
    curNodeChar[u][selfChar[u]]++; //self charecter
    sizeOfNode[u]++; //self size

    for(int v:edges[u]){
        if(v!=par){
            dfs(v, u);
            sizeOfNode[u]+=sizeOfNode[v];
            for(int i=0;i<26;i++) curNodeChar[u][i] +=curNodeChar[v][i]; //assign child's charecter also
        }
    }

    bool f=true;
    for(int i=0;i<26;i++){
        if(givenStringCharCount[i]>curNodeChar[u][i]) f=false;
    }
    if(f) minimumSize = min(minimumSize, sizeOfNode[u]);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char x;
        cin>>x;
        selfChar[i]=x-'a';
    }

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    string s; cin>>s;
    for(char x:s) givenStringCharCount[x-'a']++;

    dfs(1, -1);
    cout<<((minimumSize==200005)?-1:minimumSize)<<endl;
}