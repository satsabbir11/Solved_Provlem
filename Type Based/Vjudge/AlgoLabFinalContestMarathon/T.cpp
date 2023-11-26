#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

vector<int>ans(3005);
vector<bool>prime(3005);

void getImmidiateBiggerPrime(){
    for(int i=2;i<=3005;i++){
        if(!prime[i]){
            for(int j=i-1;j>=1;j--){
                ans[j]=i;
                if(!prime[j]) break;
            }
            for(int j=i*i;j<=3005; j+=i) prime[j]=true;
        }
    }
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);


   getImmidiateBiggerPrime();
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin>>n>>m;

        cout<<ans[n+m]-n-m<<endl;
    }
}