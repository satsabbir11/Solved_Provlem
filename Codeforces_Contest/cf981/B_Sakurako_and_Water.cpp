#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

long long ans=0, nn;

void thikKoro(vector<vector<int>>&v, int n, int m){
    int i=n, j=m, mx = 0;
    bool f=false;
    while(i<=nn and j<=nn){
        if(v[i][j]<0){
            mx = max(abs(v[i++][j++]), mx);
            f=true;
        }
        else{
            i++; j++;
        }
    }


    if(f) ans+=mx;
    else return;

    //cout<<n<<" "<<m<<" "<<mx<<endl;

    i=n, j=m;
    while(i<=nn and j<=nn){
        v[i++][j++]+=mx;
    }
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        int n, m;
        cin>>n;

        m=n;

        ans = 0, nn=n;
        vector<vector<int>>v(n+2, vector<int>(m+2));
        for(int i=1;i<=n; i++){
            for(int j=1; j<=m; j++) cin>>v[i][j];
        }

        for(int i=1;i<=n; i++){
            for(int j=1; j<=m; j++){
                if(v[i][j]<0){
                    thikKoro(v, i, j);
                }
            }
        }

        cout<<ans<<endl;
    }
}