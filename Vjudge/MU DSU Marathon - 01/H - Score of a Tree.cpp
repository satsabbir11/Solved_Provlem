#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con(f) (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

#define mxn 100005

long long par[mxn], rk[mxn];

long long find(long long a){
    return (par[a]==a) ? a : (par[a] = find(par[a]));
}

void merge(long long a, long long b){
    a = find(a);
    b = find(b);

    if(a==b) return;

    if(rk[a]<rk[b]) swap(a, b);
    rk[a]+=rk[b];
    par[b] = a;
}

struct Tree{
    long long w, x, y;
};

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   long long n;
   cin>>n;

   Tree v[n+2];

   for(long long i=1;i<n;i++){
    cin>>v[i].x>>v[i].y>>v[i].w;
   }

   sort(v+1, v+n,[](Tree a, Tree b){
    return a.w<b.w;
   });

   long long ans =0;

   for(long long i=1;i<=n;i++){
    par[i] = i;
    rk[i] = 1;
   }

   for(long long i=1;i<n;i++){
    long long x = find(v[i].x);
    long long y = find(v[i].y);

    ans+=(v[i].w * rk[x] * rk[y]);
    merge(x, y);
   }

   cout<<ans<<endl;
}
