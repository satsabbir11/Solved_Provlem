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

void init(long long a[],long long tree[],long long node, long long s, long long e)
{
  if(s==e)
  {
    tree[node]=a[e];
    return;
  }
  long long left=2*node, right=left+1, mid=(s+e)/2;
  init(a,tree, left, s, mid);
  init(a,tree, right, mid+1, e);
  tree[node]=tree[right]+tree[left];
}

void update(long long a[],long long tree[],long long node, long long s, long long e, long long in, long long v)
{
  if(in<s || e<in) return;
  if(s==e && s==in)
  {
    tree[node]=v;
    return;
  }

  long long left=2*node, right=left+1, mid=(s+e)/2;
  update(a, tree, left, s, mid, in, v);
  update(a, tree, right, mid+1, e, in, v);
  tree[node]=tree[right]+tree[left];
}

long long func(long long a[],long long tree[],long long node, long long s ,long long e, long long i, long long j)
{
  if(j<s || e<i) return 0;
  if(i<=s && e<=j) return tree[node];

  long long left=2*node, right=left+1, mid=(s+e)/2;
  long long p=func(a, tree, left, s, mid, i, j), q=func(a, tree, right, mid+1, e, i, j);
  return p+q;
}


int main()
{
    FastRead;
  
   // #ifndef sabbir
   //  freopen("input.txt", "r", stdin); 
   //  freopen("output.txt", "w", stdout);
   //  #endif

    long long n,m,i;
    cin>>n>>m;
    long long a[n+2],tree[4*n];
    for(i=1;i<=n;i++) cin>>a[i];
    init(a, tree, 1,1,n);
    while(m--)
    {
      long long p;
      cin>>p;
      if(p==2)
      {
        long long x,y;
        cin>>x>>y;
        cout<<func(a, tree, 1,1,n,x+1,y)<<endl;
      }
      else
      {
        long long x,y;
        cin>>x>>y;
        update(a, tree, 1,1,n,x+1,y);
      }
    }
}