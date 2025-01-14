#include <bits/stdc++.h>
using namespace std;

int cmp=0, mxsize=1;

int parX(vector<int>&par, int x){
    if(par[x]==x) return x;
    return par[x] = parX(par, par[x]);  
}

void connect(vector<int>&par, vector<int>&sz, int x, int y){
    int xx = parX(par, x), yy = parX(par, y);

    if(xx==yy) return;

    if(sz[xx]<sz[yy]) swap(xx, yy);
    sz[xx]+=sz[yy];
    par[yy] = xx;

    mxsize = max(mxsize, sz[xx]);
    cmp--;
}

int main(){
    int n, m; cin>>n>>m;
    cmp=n;

    vector<int>par(n+1), sz(n+1, 1);
    iota(par.begin(), par.end(), 0);

    while(m--){
        int x, y; cin>>x>>y;
        connect(par, sz, x, y);

        cout<<cmp<<" "<<mxsize<<endl;
    }
}