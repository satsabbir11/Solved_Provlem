//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")
#define inf 20002
#define MOD 1000000007


int main()
{
    FastRead;
  
   // #ifndef sabbir
   //  freopen("input.txt", "r", stdin); 
   //  freopen("output.txt", "w", stdout);
   //  #endif

   long long t,e;
   cin>>t;
   for(e=1;e<=t;e++)
   {
    long long node,edge,i,st,en,w;
    cin>>node>>edge;
    vector<long long>a[node+2];
    long long dis[node+2], cost[node+2][node+2]={};
    for(i=0;i<=node;i++) dis[i]=inf;
    for(i=0;i<edge;i++)
    {
      cin>>st>>en>>w;
      if(cost[st][en]) cost[st][en]=cost[en][st]=min(cost[st][en],w);
      else
      {
        a[st].push_back(en);
        a[en].push_back(st);
        cost[en][st]=cost[st][en]=w;
      }
    }
    cin>>st;
    queue<long long>q;
    q.push(st);
    dis[st]=0;
    while(!q.empty())
    {
      long long cr=q.front();
      q.pop();
      for(i=0;i<a[cr].size();i++)
      {
        long long x=a[cr][i];
        long long v=max(cost[x][cr],dis[cr]);
        if(dis[x]>v)
        {
          dis[x]=v;
          q.push(x);
        }
      }
    }
    cout<<"Case "<<e<<":\n";
    for(i=0;i<node;i++)
      {
        if(d[i]==inf) cout<<"Impossible"<<endl;
        else cout<<dis[i]<<endl;
      }
   }
}