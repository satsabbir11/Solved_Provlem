#include<bits/stdc++.h>
using namespace std;

struct shirt{
    int p, a, b;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    int t;
    t=1;
    while (t--) {
        int n;
        cin>>n;

        shirt v[n+2];
        
        for(int i=1;i<=n;i++){
            cin>>v[i].p;
        }

        for(int i=1;i<=n;i++){
            cin>>v[i].a;
        }
        for(int i=1;i<=n;i++){
            cin>>v[i].b;
        }

        sort(v+1, v+1+n,[](shirt x, shirt y){ //sort respect to price
            return x.p<y.p;
        });

        queue<int>p[4];      // 3 color, so 3 types of queue

        for(int i=1;i<=n;i++){  // push index based on color (array already sorted based on price)
            p[v[i].a].push(i);
            p[v[i].b].push(i);
        }

        map<int, bool>mp;

        int qq;
        cin>>qq;
        while(qq--){
            int x;
            cin>>x;

            bool f=false; // for check if I able to pick

            while(!p[x].empty()){
                int i = p[x].front();
                p[x].pop();
                if(!mp[i]){          //to check those whick are not selected
                    mp[i] = true;   //mark for not  to use multiple time
                    f=true;
                    cout<<v[i].p<<" ";
                    break;
                }
            }
            if(!f) cout<<-1<<endl; // if I not able to pick 
        }

    }
}
