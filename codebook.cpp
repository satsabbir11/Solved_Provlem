/**
 * Author: Sabbir Ahmed Talukdar
 * Version: 1.0.0
*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define ull unsigned long long
#define con (f?"YES":"NO")
#define Dpos(n) fixed << setprecision(n)
#define CLR(a) memset(a, -1, sizeof(a))
#define CLN(a) memset(a, 0, sizeof(a))
#define sortn(a,x,y) sort(a+x, a+x+y)
#define sortv(s) sort(s.begin(), s.end())
#define reversev(s) reverse(s.begin(), s.end())
#define reversesortv(s) sortv(s); reversev(s)
#define lowerbound(v,x) lower_bound(v.begin(), v.end(), x)-v.begin()+1
#define upperbound(v,x) upper_bound(v.begin(), v.end(), x)-v.begin()
#define loj(i,j) "Case "<<i<<": "<<j
#define auto(x,a) for (auto& x : a)

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
}

/**
 * Description: BFS
*/

vector<int>p[20005];
bool vis[20005]={};
void Bfs(int x){
    queue<int>q;
    q.push(x);
    vis[x]=true;
    while(!q.empty()){
       int u=q.front();
       q.pop();
       for(int i=0;i<p[u].size();i++){
       int v=p[u][i];
        if(!vis[v]){
            q.push(v);
            vis[v]=true;
        }
       }
    }
}

/**
 * Description: nth_prime
*/

int nth_prime[105], vis[105]={};
void nthPrime(int limit=101){
    int ii=1;
    nth_prime[ii]=2;
    for(int i=3;i<=limit;i+=2){
        if(!vis[i]){
            nth_prime[++ii]=i;
            for(int j=i*i;j<=limit;j+=i) vis[j]=1;
        }
    }
}

/*
Snippet : DFS on tree start
*/
vector<vector<int>> p;
vector<long long> depth;
vector<long long> reverse_depth;
void dfs(int u, int par)
{
    if (p[u].size() == 1 && p[u][0] == par){
        depth[u] = depth[par]+1;
        reverse_depth[u] = 1;
    }
    else
    {
        for (auto v : p[u])
        {
            if (v != par)
            {
                depth[v] = 1 + depth[u];
                dfs(v, u);
                reverse_depth[u] = 1 + reverse_depth[v];
            }
        }
    }
}
void solve(int n)
{
    p.assign(n + 2, vector<int>());
    depth.assign(n + 2, 0);
    reverse_depth.assign(n + 2, 0);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p[x].push_back(y);
        p[y].push_back(x);
    }
    depth[1]=1;
    dfs(1, -1);
    int x = 2;
    cout<<depth[x]<<" "<<reverse_depth[x]<<endl;
}

/*
Snippet : DFS on tree end
*/

int sum_of_absolute_differences_of_all_pairs_in_a_given_array(int a[], int n)
{
    int ans = 0;
    sort(a, a + n);
    for (long long i = 0; i < n; i++)
        ans += a[i] * (2 * i - n + 1);
    return ans;
}

int unique_zigzag(vector<int> a)
{
    int n, ans;
    ans = n = unique(a.begin(), a.end()) - a.begin();
    for (int i = 0; i < n - 2; i++) ans -= ((a[i] < a[i + 1] && a[i + 1] < a[i + 2]) + (a[i] > a[i + 1] && a[i + 1] > a[i + 2]));
    return ans;
}

/*
Snippet : Dijkstra
*/
int main()
{
    int n, t;
    cin >> n;
    t = n;
    vector<pair<int, int>> edges[n + 2];
    vector<long long> dist(n + 2, 1e18);
    while (t--)
    {
        int head, q;
        cin >> head >> q;

        while (q--)
        {
            int x, y;
            cin >> x >> y;
            edges[head].push_back({x, y});
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int u = pq.top().second, dis = pq.top().first;
        pq.pop();
        if (dist[u] < dis)
            continue;
        for (auto e : edges[u])
        {
            int w = e.second, v = e.first;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << i << " " << dist[i] << endl;
}

/*
Snippet : Another Dijkstra
*/
int main()
{
    long long t, k=1;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<pair<long long, long long>> edges[n + 2];
        vector<bool> vis(n + 2);
        vector<long long> dist(n + 2, 1e12), par(n + 2, -1);
        while (m--)
        {
            long long x, y, w;
            cin >> x >> y >> w;
            edges[x].push_back({y, w});
            edges[y].push_back({x, w});
        }
        par[1] = -1;
        dist[1] = 0;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 1});
        while (!pq.empty())
        {
            long long u = pq.top().second;
            pq.pop();
            if (vis[u])
                continue;
            vis[u] = true;
            for (auto e : edges[u])
            {
                long long w = e.second, v = e.first;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    par[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        if(dist[n]==1e12) cout<<"Case "<<k<<": Impossible";
        else cout<<loj(k,dist[n]);
        cout<<endl;
        k++;
    }
}