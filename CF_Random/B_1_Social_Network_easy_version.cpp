#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    t=1;
    while (t--) {
        long long n, k;
        cin>>n>>k;
        
        long long a[n+2];
        deque<int>q;
        map<int, bool>mp;
        for(long long i=1;i<=n;i++){
            int x;
            cin>>x;
            if(!mp[x]){
                q.push_front(x);
                mp[x]=true;
                if(q.size()>k){
                    int y = q.back();
                    mp[y]=false;
                    q.pop_back();
                }
            }
        }

        cout<<q.size()<<endl;
        while(!q.empty()){
            int x = q.front();
            q.pop_front();
            cout<<x<<" ";
        }
    }
}