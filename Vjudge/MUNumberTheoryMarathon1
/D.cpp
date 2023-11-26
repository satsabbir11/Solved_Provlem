#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long n, m;
    cin>>n>>m;
    long long ans =1;
    for(long long i=1;i<=min(n, m);i++){
        ans*=i;
    }
    cout<<ans<<endl;
}