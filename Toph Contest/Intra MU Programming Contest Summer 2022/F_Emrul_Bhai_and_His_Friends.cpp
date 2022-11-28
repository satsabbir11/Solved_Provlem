#include<bits/stdc++.h>
using namespace std;

vector<long long>p[105];

bool vis[105]={};
long long a[105];

long long Bfs(long long x){
   queue<long long>q;
   q.push(x);
   vis[x]=true;
   long long cnt=0;
   cnt+=a[x];

   while(!q.empty()){
      long long u=q.front();
      q.pop();

      for(long long i=0;i<p[u].size();i++){
         long long v=p[u][i];
         if(!vis[v]){
            q.push(v);
            cnt+=a[v];
            vis[v]=true;
         }
      }
   }
   return cnt;
}

int main()
{
   int t;
   cin>>t;
   while(t--){
      long long n,m,l;
      cin>>n>>m>>l;

      for(long long i=0;i<105;i++){
         memset(p, 0, sizeof(p));
         vis[i]=false;
      }

      for(long long i=1;i<=m;i++){
         cin>>a[i];
      }

      while(l--){
         long long x,y;
         cin>>x>>y;
         p[x].push_back(y);
         p[y].push_back(x);
      }

      vector<long long>g;
      long long cnt=0;

      for(long long i=1;i<=m;i++){
         if(!vis[i]){
         long long value = Bfs(i);
         g.push_back(value);
         }
      }

      sort(g.begin(), g.end());
      reverse(g.begin(), g.end());

      long long qq=g.size();

      long long ll=min(n,qq);

      for(long long i=0;i<ll;i++) cnt+=g[i];
      cout<<cnt<<endl;
   }
}