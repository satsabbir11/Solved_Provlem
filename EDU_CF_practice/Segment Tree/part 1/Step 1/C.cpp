//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")
#define inf 100002
#define MOD 1000000007
pair<long long, long long> tree[4*inf];
long long a[inf];

pair<long long, long long> modify(pair<long long, long long>a, pair<long long, long long>b)
{
  if(a.first<b.first) return a;
  if(a.first>b.first) return b;
  return {a.first,a.second+b.second};
}

void init(long long node, long long s, long long e)
{
  if(s==e)
  {
    tree[node]={a[s],1};
  }
 else
 {
   long long mid=(s+e)/2;
  init(node*2,s,mid);
  init(1+node*2,mid+1,e);
  tree[node] = modify(tree[2*node],tree[1+node*2]);
 }
}
void update(long long node, long s, long long e, long long in, long long v)
{
   if(s==e) tree[node] = {v, 1};
    else {
        long long mid = (s+e)/2;
        if(in <= mid) update(2*node, s, mid, in, v); 
        else update(2*node+1, mid+1, e,in, v);
        tree[node] = modify(tree[2*node], tree[2*node+1]);
    }

}

pair<long long, long long> func(long long node, long long s, long long e, long long x, long long y)
{
  if(y<s || e<x) return {MOD,0};
  if(s>=x && y>=e) return tree[node];
  long long mid=(s+e)/2;
 pair<long long,long long> p=func(2*node,s, mid, x, y), q=func(1+2*node, mid+1, e,x, y);
  return modify(p,q);
}

int main()
{
  // #ifndef sabbir
  //   freopen("input.txt", "r", stdin); 
  //   freopen("output.txt", "w", stdout);
  //   #endif
  
  long long n,m,i;
  cin>>n>>m;
  for(i=1;i<=n;i++) cin>>a[i];
  init(1,1,n);
  while(m--)
  {
    long long op;
    cin>>op;
    if(op==1)
    {
      long long x,y;
      cin>>x>>y;
      update(1,1,n,x+1,y);
    }
    else
    {
      long long x,y;
      cin>>x>>y;
      pair<long long, long long>a=func(1,1,n,x+1,y);
      cout<<a.first<<" "<<a.second<<endl;
    }
  }
}