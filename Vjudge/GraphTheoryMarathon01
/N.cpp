#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

vector<vector<int>>p(1005);
bool f= false;
int tt;

void generatePrimeFactor(){
    for(int i=2;i<=1002;i++){
        int n =i;
        int prime = 2;
        int fixPrime = 0;
        while(n>1){
            fixPrime = 0;
            while(n%prime==0){
                fixPrime = prime;
                n/=prime;
            }
            prime++;
            if(fixPrime) p[i].push_back(fixPrime);
        }
        if(fixPrime == i) p[i].clear();
    }
}

void dfs(int u,  vector<int>&dis){
    
    for(int i=0;i<p[u].size();i++){
        int v = u+p[u][i];
        if(v<=tt && dis[v]>(dis[u]+1)){
            dis[v] = dis[u]+1;
            //cout<<v<<" "<<dis[v]<<endl;
            if(v==tt) return;
            dfs(v, dis);
        }
    }
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   generatePrimeFactor();

    long long t;
    cin >> t;
    for(int k =1;k<=t;k++){
        long long n;
        cin>>n>>tt;

        vector<int>dis(1005, 10000);

        dis[n] = 0;
        dfs(n, dis);

        if(dis[tt]==10000) dis[tt] = -1;

        cout<<loj(k, dis[tt])<<endl;
    }
}