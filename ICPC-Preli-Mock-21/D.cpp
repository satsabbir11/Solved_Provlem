#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);


long long vis[1000005];

vector<long long>node[1000005];
string p[1000005], s;

void dfs(long long u){
    p[u]+=s[u-1];
    vis[u]=1;

    for(long long i=0;i<node[u].size();i++){
        long long v=node[u][i];
        if(!vis[v]){
            vis[v]=1;
            p[v]=p[u];
            dfs(v);
        }
    }
}

void clr(){
    for(long long i=0;i<1000005;i++){
        node[i].clear();
        p[i].clear();
        vis[i]=0;
    }
}

int main() {
    FastRead

    long long t;
    cin>>t;
    for( long long jj=1;jj<=t;jj++){
        clr();
        long long n;
    cin>>n;

    cin>>s;

    for(long long i=1;i<n;i++){
        long long x,y;
        cin>>x>>y;

        node[x].push_back(y);
        node[y].push_back(x);
    }

    dfs(1);

    long long ans=0;
    for(long long i=1;i<=n;i++){
        string ss,tt;
        //cout<<p[i]<<" ";
        tt=p[i];
        reverse(tt.begin(), tt.end());
        if(tt==p[i]) ans++;
       // cout<<i<<" "<<tt<<endl;
        //cout<<ss<<endl;
    }
    long long gc=__gcd(ans,n);
    cout<<"Case "<<jj<<": "<<ans/gc<<"/"<<n/gc<<endl;
    }
}