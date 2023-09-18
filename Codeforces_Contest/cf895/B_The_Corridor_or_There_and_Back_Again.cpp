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
        int n, mn =1000;
        cin>>n;

        pair<int, int>p[n+2];
        
        for(long long i=1;i<=n;i++){
            cin>>p[i].first>>p[i].second;
        }

        for(long long i=1;i<=n;i++){
            int a = p[i].first, b = p[i].second;
            mn = min(mn, a + (b-1)/2);
        }
        cout<<mn<<endl;
    }
}