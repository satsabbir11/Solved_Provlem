#include <bits/stdc++.h>
using namespace std;

int find(vector<int>&par, int a){
    if(par[a]==a) return a;
    return par[a] = find(par, par[a]);
}

int merge(vector<int>&par, vector<int>&rk, int a, int b){
    a=find(par, a);
    b=find(par, b);

    if(a==b) return rk[a];

    if(rk[a]<rk[b]) swap(a,b);
    rk[a]+=rk[b];

    par[b] = a;
    return rk[a];
}

int main(){
    int n, m; cin>>n>>m;
    vector<int>par(n+1);
    vector<int>rk(n+1, 1);
    iota(par.begin(), par.end(), 0);

    for(int i=1;i<=m;i++){
        int x, y; cin>>x>>y;
        merge(par, rk, x, y);
    }

    vector<pair<int, int>>p;

    for(int i=2;i<=n;i++){
        if(find(par, 1)!=find(par, i)){
            p.push_back({1,i});
            merge(par, rk, 1,i);
        }
    }

    cout<<p.size()<<endl;
    for(auto [x,y]:p){
        cout<<x<<" "<<y<<endl;
    }
}