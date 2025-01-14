#include <bits/stdc++.h>
using namespace std;

int findPar(vector<int>&par, int x){
    if(par[x]==x) return x;
    return findPar(par, par[x]);
}

void connectNode(vector<int>&par,vector<int>&size, int x, int y){
    int xx = findPar(par, x), yy = findPar(par, y);
    if(xx!=yy){
        if(size[xx]<size[yy]) swap(xx, yy);
        size[xx]+=size[yy];
        par[yy]=xx;
    }
}


int main(){
    int n, e; cin>>n>>e;
    vector<int>par(n+2), size(n+2, 1);
    iota(par.begin(), par.end(), 0);
    while(e--){
        int t, x, y;
        cin>>t>>x>>y;
        if(t==1){
            if(findPar(par, x)==findPar(par, y)) cout<<1<<endl;
            else cout<<0<<endl;
        }else{
            connectNode(par, size, x, y);
        }
    }
}