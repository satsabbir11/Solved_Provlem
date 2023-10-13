#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

long long start;


bool isCycle(vector<vector<int>>& p, vector<bool>& vis, int u, int prev=-1) {
    vis[u] = true;
    for (int v : p[u]) {
        if (v != prev) {
            if (vis[v]) {
                start = v;
                return true;
            }
            if (isCycle(p, vis, v, u)) {
                return true;
            }
        }
    }
    return false;
}


void eachNodeDistance(vector<vector<int>>& p, vector<int>& dis, int u) {
    for (int v : p[u]) {
        if (dis[v] > dis[u] + 1) {
            dis[v] = dis[u] + 1;
            eachNodeDistance(p, dis, v);
        }
    }
}


int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, pp, cc;
        cin>>n>>pp>>cc;

        vector<vector<int>>p(n+2);
        vector<bool>vis(n+2);
        vector<int>dis(n+2, INT32_MAX);
        
        for(int i=1;i<=n;i++){
            int x, y;
            cin>>x>>y;
            p[x].push_back(y);
            p[y].push_back(x);
        }



        if(pp==cc){
            cout<<"NO"<<endl;
            continue;
        }


        isCycle(p, vis, cc);

        //if on the starting point of cycle
        if(start==cc){
            cout<<"YES"<<endl;
            continue;
        }

        dis[start] = 0;
        eachNodeDistance(p, dis, start);

        //who's distance is minimum from starting point of cycle
        bool f = (dis[cc]<dis[pp]);
        cout<<con<<endl;
        
    }
}