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
        long long n, k;
        cin>>n>>k;

        bool f=false;

        if(n%2==0){
            if(k%4==1 or k%4==0) f=true;
        }else{
            if(k%4==3 or k%4==0) f=true;
        }
        cout<<con<<endl;
    }
}