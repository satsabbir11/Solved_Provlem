#include<bits/stdc++.h>
using namespace std;
#define mxn 100002
vector<long long>a[mxn];
bool vis[mxn];
long long dis[mxn], cat[mxn] ,n,m;
long long maxx;
 
void dfs(long long s)
{
    vis[s]=true;
    //cout<<s<<endl;
    for(auto i: a[s])
    {
        if(!vis[i])
        {
          if(cat[i]) dis[i]=dis[s]+1;
          else dis[i]=0;
 
          if(dis[i]<=m) dfs(i);
        }
    }
}
int main()
{
 
 // #ifndef sabbir
 //    freopen("input.txt", "r", stdin); 
 //    freopen("output.txt", "w", stdout);
 //    #endif
 
   cin>>n>>m;
   for(long long i=1;i<=n;i++) cin>>cat[i];
   for(long long i=0;i<n-1;i++)
   {
    long long x,y;
    cin>>x>>y;
    a[x].push_back(y);
    a[y].push_back(x);
   }
   if(cat[1]) dis[1]=1;
   dfs(1);
   long long cnt=0;
   for(long long i=2;i<=n;i++)
   {
    long long l=a[i].size();
    if(l==1 && vis[i]) cnt++;
   }
   cout<<cnt<<endl;
}