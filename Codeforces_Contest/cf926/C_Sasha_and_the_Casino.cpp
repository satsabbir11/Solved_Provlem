#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define loj(i,j) "Case "<<i<<": "<<j
#define con (f?"YES":"NO")

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long k, x, a;
        cin>>k>>x>>a;

        long long spend =0, cur=1, rem=a;
        bool f=true;

        for(long long i=1;i<=x+1;i++){
            if(cur>rem){
                f=false;
                break;
            }
            spend+=cur;
            rem-=cur;
            cur = (spend+k-1)/(k-1);
        }
        cout<<con<<endl;
    }
}
