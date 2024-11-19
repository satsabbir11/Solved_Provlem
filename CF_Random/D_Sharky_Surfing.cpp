#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int t; cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        vector<pair<int, int>>obs(n), p(m);

        for(int i=0; i<n; i++){
            cin>>obs[i].first>>obs[i].second;
        }

         for(int i=0; i<m; i++){
            cin>>p[i].first>>p[i].second;
        }

        priority_queue<int>pq;
        int i,j, jump=0, ans=0;
        bool f=true;
        i=j=0;
        while(i<n and f){
            while(j<m){
                if(p[j].first<obs[i].second) pq.push(p[j++].second);
                else break;
            }
            int target=obs[i].second-obs[i++].first;
            while(!pq.empty() and jump<=target){
                jump+=pq.top(); pq.pop();
                ans++;
            }
            if(jump<=target) f=false;
        }
        if(f) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}