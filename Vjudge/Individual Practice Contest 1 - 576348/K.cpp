#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long  t;
    cin >> t;
    while (t--) {
        long long  i, j;
        cin>>i>>j;

        long long cnt =0;
        
        while(i!=j){
            if(i<j) j/=2;
            else i/=2;
            cnt++;
        }
        cout<<cnt<<endl;
    }
}