#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        if(b<=3){
            cout<<-1<<endl;
            continue;
        }

        if(a==b && a%2){
            bool f=true;
            for(long long i=3;i*i<=a;i++){
                long long j = a-i;
                if(__gcd(i, j)!=1){
                    cout<<i<<" "<<j<<endl;
                    f = false;
                    break;
                }
            }
            if(f) cout<<-1<<endl;
        }
        else{
            if(b%2) b--;
            cout<<b-2<<" "<<2<<endl;
        }
    }
}
