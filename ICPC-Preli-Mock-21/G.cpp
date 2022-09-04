
//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000010
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")

#define Dpos(n) fixed << setprecision(n)

#define CLR(a) memset(a, -1, sizeof(a))
#define CLN(a) memset(a, 0, sizeof(a))

#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define max5(a,b,c,d,e) max(max4(a,b,c,d),e)
#define min5(a,b,c,d,e) min(min4(a,b,c,d),e)

#define sortn(a,n,m) sort(a+m, s+m+n)
#define sortt(s) sort(s.begin(), s.end())
#define reversee(s) reverse(s.begin(), s.end())
#define reversesortt(s) sortt(s); reversee(s)
#define pb push_back
#define loj(i,j) "Case "<<i<<": "<<j
#define gap " "

// for (auto& x : a) cin >> x;

vector<long long>node[30005];

long long wt[30005], vis[30005], dis[30005];

long long bfs(long long root){
    dis[root]=0;
    vis[root]=1;
   
    long long ans=0;

    queue<long long>q;
    q.push(root);

    while(!q.empty()){

        long long u=q.front();
        q.pop();


        for(long long i=0;i<node[u].size();i++){
            long long v=node[u][i];
            if(!vis[v]){
                q.push(v);
                vis[v]=1;


                dis[v]=dis[u]+1;
                long long gg=wt[root]-wt[v];
                
                if(dis[v]%2) gg*=-1;

                ans+=gg; 
            }
        }
    }

    return ans;
}

int main() {
    FastRead

    long long t;
    cin >> t;
    for(long long jj=1;jj<=t;jj++) {
         for(long long i=0;i<30005;i++){
            node[i].clear();
            wt[i]=0;
            vis[i]=0;
            dis[i]=0;
         }
        long long n;
        cin>>n;

        for(long long i=1;i<=n;i++) cin>>wt[i];
        
        for(long long i=1;i<n;i++){
            long long x,y;
            cin>>x>>y;
            node[x].push_back(y);
            node[y].push_back(x);
        }

        long long mx=0, ans=1;

        for(long long i=1;i<=n;i++){
            for(long long i=0;i<=n;i++){
            vis[i]=0;
            dis[i]=0;
            }
            long long dx=mx;
            mx=max(bfs(i),mx);
            if(dx<=mx) ans=i;

        }

        cout<<loj(jj,ans)<<endl;
    }
}