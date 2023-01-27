/**
 * Author: Sabbir Ahmed Talukdar
 * Version: 1.0.0
*/

/**
 * Last Modified by: Sabbir Ahmed Talukdar
 * Last Modified time: 2023-01-27 
 * Description: Boilerplate for competitive programming
*/


#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
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

#define sortn(a,x,y) sort(a+x, a+x+y)
#define sortv(s) sort(s.begin(), s.end())
#define reversev(s) reverse(s.begin(), s.end())
#define reversesortv(s) sortv(s); reversev(s)

#define lowerbound(v,x) lower_bound(v.begin(), v.end(), x)-v.begin()+1
#define upperbound(v,x) upper_bound(v.begin(), v.end(), x)-v.begin()

#define pb push_back
#define loj(i,j) "Case "<<i<<": "<<j
#define gap " "

#define auto(x,a) for (auto& x : a)

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        
        long long a[n+2];
        for(long long i=1;i<=n;i++) cin>>a[i];

        for(long long i=1;i<=n;i++) cout<<a[i]<<" ";
    }
}


/**
 * Last Modified by: Sabbir Ahmed Talukdar
 * Last Modified time: 2023-01-27 
 * Description: BFS
 * Time Complexity: O(V+E)
 * Space Complexity: O(V+E)
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
 * Last Modified by: Sabbir Ahmed Talukdar
 * Last Modified time: 2023-01-27 
 * Description: nth_prime
 * Time Complexity: O(nloglogn)
 * Space Complexity: O(n)
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