#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int dp(vector<vector<int>>&a,vector<vector<int>>&d, int i, int j, int n, int m){
    if(i==m || j==n || a[i][j]==0) return 0;
    if(d[i][j]) return d[i][j];

    d[i][j] = a[i][j] + max(dp(a, d, i+1, j+1, n, m), dp(a, d, i+1, j, n, m));
    return d[i][j];
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t, k=0;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;


        vector<vector<int>>a(2*n-1, vector<int>(n));
        vector<vector<int>>d(2*n-1, vector<int>(n, 0));

        for(int i=0;i<2*n-1;i++){
            if(i<n) for(int j=0;j<=i;j++) cin>>a[i][j];
            else for(int j=0; j<n; j++){
                if((i-n)<j) cin>>a[i][j];
            }
        }  
        cout<<loj(++k, dp(a, d, 0, 0, n, 2*n-1))<<endl;
    }
}