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
long long tree[4*inf],a[inf];

void init(long long node, long long s, long long e)
{
  if(s==e)
  {
    tree[node]=a[s];
    return;
  }
  long long left=node*2, right= 1+node*2, mid=(s+e)/2;
  init(left,s,mid);
  init(right,mid+1,e);
  tree[node]=tree[right]+tree[left];
}

long long func(long long node, long long s, long long e, long long i, long long j)
{
  if(s>j || i>e) return 0;
  if(s>=i && j>=e) return tree[node];
  long long left=node*2, right= 1+node*2, mid=(s+e)/2;
  long long p=func(left,s,mid,i,j), q=func(right,mid+1,e,i,j);
  return p+q;
}

void update(long long node, long long s, long long e, long long in, long long v)
{
 if(in<s || e<in) return;
  if(in<=s && e<=in)
  {
    tree[node]=v;
    return;
  }
  long long left=node*2, right= 1+node*2, mid=(s+e)/2;
  update(left,s,mid,in,v);
  update(right,mid+1,e,in,v);
  tree[node]=tree[right]+tree[left];
}


int main()
{
  // #ifndef sabbir
  //   freopen("input.txt", "r", stdin); 
  //   freopen("output.txt", "w", stdout);
  //   #endif


  long long n,m;
  cin>>n>>m;
  for(long long i=1;i<=n;i++) cin>>a[i];
  init(1,1,n);
  while(m--)
  {
    long long op;
    cin>>op;
    if(op==1)
    {
      long long in,v;
      cin>>in>>v;
      update(1,1,n,in+1,v);
    }
    else
    {
      long long ss,ee;
      cin>>ss>>ee;
      cout<<func(1,1,n,ss+1,ee)<<endl;
    }
  }
}