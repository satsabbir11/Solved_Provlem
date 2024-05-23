#include<bits/stdc++.h>
using namespace std;
//K= root, n=node
void find(vector<long long>a[], long long n, long long k)
{
  queue<long long>q;
  long long vis[n+2]={};
  long long dis[n+2]={},maxx=0ll;
  vis[k]=0;
  dis[k]=1;
  q.push(k);
  while(!q.empty())
  {
    long long x=q.front();
    q.pop();
    long long l=a[x].size();
    for(long long i=0;i<l;i++)
    {
      long long y=a[x][i];
      if(!vis[y])
      {
        q.push(y);
        vis[y]=1;
        dis[y]=dis[x]+1;
        maxx=max(maxx,dis[y]);
      }
    }
  }
  cout<<maxx<<endl;
}