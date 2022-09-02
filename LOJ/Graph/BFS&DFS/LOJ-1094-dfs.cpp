
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

long long n, vis[30005],dis[30005];
vector<long long>wt[30005],node[30005];

void dfs(long long u){
	vis[u]=1;
	for(long long i=0;i<node[u].size();i++){
		long long v=node[u][i];
		if(!vis[v]){
			vis[v]=1;
			dis[v]=dis[u]+wt[u][i];
			dfs(v);
		}
	}
}

void clr(bool f){
	for(long long i=0;i<30005;i++){
		vis[i]=0;
		dis[i]=0;
		if(f){
			node[i].clear();
			wt[i].clear();
		}
	}
}

int main() {
    FastRead

    long long t;
    cin >> t;

    for(long long jj=1;jj<=t;jj++){
    	clr(1);

        cin>>n;
        long long x,y,z;
        for(long long i=1;i<n;i++){
        	
        	cin>>x>>y>>z;

        	node[x].push_back(y);
        	node[y].push_back(x);

        	wt[x].push_back(z);
        	wt[y].push_back(z);
        }

        dfs(0);


        long long first, mx=0;

        for(long long i=0;i<n;i++){
        	if(mx<dis[i]){
        		mx=dis[i];
        		first=i;
        	}
        }

        clr(0);

        dfs(first);
        mx=0;

        for(long long i=0;i<n;i++){
        	if(mx<dis[i]){
        		mx=dis[i];
        		first=i;
        	}
        }

        cout<<loj(jj,mx)<<endl;

    }
}