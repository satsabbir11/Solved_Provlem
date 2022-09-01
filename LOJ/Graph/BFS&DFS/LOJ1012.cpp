
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

long long n, m, a[25][25], vis[25][25];

long long dfs(long long i, long long j){
    int cnt=0;


    if(a[i][j]==0) return 0;

    if(!vis[i][j]){
        vis[i][j]=1;


        cnt++;
        cnt+=dfs(i+1,j);
        cnt+=dfs(i-1,j);
        cnt+=dfs(i,j-1);
        cnt+=dfs(i,j+1);
        return cnt;

        
    }
    else return 0;
}

void clr(){
    for(int i=0;i<25;i++){
        for(int j=1;j<25;j++){
            a[i][j]=0;
            vis[i][j]=0;
        }
    }
}

int main() {
    FastRead

    long long t;
    cin >> t;
    for(int jj=1;jj<=t;jj++) {
        cin>>m>>n;

        clr();
        
        long long start_i, start_j;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                char s;
                cin>>s;
                if(s=='#') a[i][j]=0;
                else a[i][j]=1;
                if(s=='@') {start_i=i; start_j=j;}
            }
        }
        //cout<<start_i<<" "<<start_j<<" "<<a[start_i][start_j]<<endl;
        cout<<loj(jj,dfs(start_i, start_j))<<endl;
    }
}