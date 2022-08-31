
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

vector<int>p[20005];

bool node_type[20005]={}, vis[20005]={};

long long newBfs(int x){
    long long vam=0, lk=0;
    queue<int>q;
    q.push(x);

    node_type[x]=true;
    vis[x]=true;
    lk++;

    while(!q.empty()){
       int u=q.front();
       q.pop();

       for(int i=0;i<p[u].size();i++){
       int v=p[u][i];
        if(!vis[v]){
            q.push(v);
            vis[v]=true;

            if(node_type[u]==false){
                lk++;
                node_type[v]=true;
            }
            else{
                vam++;
                node_type[v]=false;
            }
        }
       }
    }

    return max(vam,lk);
}

void clr(){
    memset(node_type, false, sizeof(node_type));
    memset(vis, false, sizeof(vis));

    for(int i=0;i<20005;i++) p[i].clear();
}

int main() {
    FastRead

    int t;
    cin >> t;
    for(int j=1;j<=t;j++) {
        clr();

        int n;
        long long sum=0;
        cin>>n;

        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            p[x].push_back(y);
            p[y].push_back(x);
        }

        for(int i=0;i<20005;i++) if(!vis[i] && !p[i].empty()) sum+=newBfs(i);

        cout<<loj(j,sum)<<endl;
    }
}