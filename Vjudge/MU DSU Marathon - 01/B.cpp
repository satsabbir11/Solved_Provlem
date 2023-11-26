#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int rk[100005], par[100005];

int find(int a){
    if(par[a]==a) return a;
    return par[a] = find(par[a]);
}

int merge(int a, int b){
    a = find(a);
    b = find (b);

    if(rk[a]<rk[b]) swap(a, b);
    par[b] = a;
    rk[a]+=rk[b];
    return rk[a];
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   int n, m;
   cin>>n>>m;

   for(int i=1;i<=n;i++) {
    rk[i]=1;
    par[i]=i;
   }

   while(m--){
    int a, b;
    cin>>a>>b;
    if(find(a) != find(b)) merge(a, b);
   }

   vector<pair<int, int>>p;
   int ans =0;

   for(int i=2;i<=n;i++){
     if(find(1) != find(i)){
        ans++;
        merge(1, i);
        p.push_back({1, i});
     }
   }

   cout<<ans<<endl;
   for(auto x:p){
    cout<<x.first<<" "<<x.second<<endl;
   }
}