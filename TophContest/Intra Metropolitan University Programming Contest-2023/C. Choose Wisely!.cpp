#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;

ll cost[N][7];


void solve(int cs){
    int n;
    cin >> n;
    
    for(int i=1;i<=5;i++) cost[i][n+1]=2e5+10;

    for(int j = 1;j <= 5;j++){
        for(int i = 1;i <= n;i++){
            cin >> cost[i][j];
        }
    }
    ll ans = 0;
    for(int i = 2;i <= n+1;i++){
         ll mx = 0;
        for(int j = 1;j <= 5;j++){
            for(int k = 1;k <= 5;k++){
                if(k != j && cost[i - 1][k] < cost[i][j]){ 
                    mx = max(mx, cost[i - 1][k]);
                }
            }
        }
        if(mx==0){
            ans = -1;
            break;
        }
        ans +=mx;
    }
    cout << "Case #" << cs << ": ";
    if(~ans) cout << ans << endl;
    else cout << "Impossible!" << endl;
}


int main() {
    int tc = 1, cs = 1;
    cin >> tc;
    while(tc--){
         solve(cs++);
    }
}