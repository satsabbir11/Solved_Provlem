#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j


vector<int>generateDivisor(int n = 1e6){
    vector<int>divisor(n+1, 0);
    for(int i=2;i<=n;i++){
        if(divisor[i]==0){
            for(int j=i;j<=n;j+=i){
                divisor[j] ++;
            }
        }
    }
    return divisor;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;

    vector<int>v= generateDivisor();

    while (t--) {
        long long a, b, k;
        cin>>a>>b>>k;
        int ans =0;

        for(int i=a; i<=b;i++){
            if(v[i]==k) ans++;
        }
        cout<<ans<<endl;
    }
}