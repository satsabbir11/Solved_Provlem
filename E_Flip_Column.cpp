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
        
        long long a[n+2][m+2];
        for(long long i=1;i<=n;i++){
            for(long long j=1; j<=m; j++){
                cin>>a[i][j];
            }
        }

         for(long long i=1;i<=m;i++){
            long long cnt = 0;
            for(long long j=1; j<=n; j++){
                cin>>a[i][j];
            }
        }
    }
}