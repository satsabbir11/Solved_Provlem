#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin>>n>>m;
        
        char a[n+2][m+2];
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m; j++){
                cin>>a[i][j];
            }
        }

        bool f1 =true, f2 =true;


        for(long long i=1;i<=n;i++){
            int u = 0, d= 0;
            for(long long j=1;j<=m; j++){
                if(a[i][j]=='U') u++;
                if(a[i][j]=='D') d++;
            }
            if(u%2==1 || d%2==1) f1 = false;
        }

        for(long long i=1;i<=m;i++){
            int u = 0, d= 0;
            for(long long j=1;j<=n; j++){
                if(a[j][i]=='L') u++;
                if(a[j][i]=='R') d++;
            }
            if(u%2==1 || d%2==1) f2 = false;
        }

        if(!(f1&f2)){
            cout<<-1<<endl;
            continue;
        }

        vector<vector<int>>v(n+2, vector<int>(m+2, -1));
        int cnt =0;
        for(int i=1;i<=n; i++){
            
            for(int j =1; j<=m ; j++){
                char c = a[i][j];
                if(c=='U'){
                    v[i][j]= 1-cnt;
                }
                else if(c=='D'){
                    v[i][j]= 1-cnt;
                }
                cnt = 1-cnt;
            }
            cnt = 1-cnt;
        }
        cnt =0;
        for(int i=1;i<=m; i++){
            for(int j =1; j<=n ; j++){
                char c = a[j][i];
                if(c=='L'){
                    v[j][i]= 1-cnt;
                }
                else if(c=='R'){
                    v[j][i]= 1-cnt;
                }
                cnt = 1-cnt;
            }
            cnt = 1-cnt;
        }

         bool f =true;

        for(int i=1;i<=n; i++){
            int w = 0, b=0;
            for(int j =1; j<=m ; j++){
                if(v[i][j]==1) w++;
                else if(v[i][j]==0) b++;
            }
            if(w!=b) f =false;
        }

        for(int i=1;i<=m; i++){
            int w = 0, b=0;
            for(int j =1; j<=n ; j++){
                if(v[j][i]==1) w++;
                else if(v[j][i]==0) b++;
            }
            if(w!=b) f =false;
        }

         if(!f){
            cout<<-1<<endl;
            continue;
        }

       for(int i=1;i<=n; i++){
            for(int j =1; j<=m ; j++){
                if(v[i][j]==-1) cout<<'.';
                else if(v[i][j]==1) cout<<'W';
                else if(v[i][j]==0) cout<<'B';
            }
            cout<<endl;
        }
    }
}