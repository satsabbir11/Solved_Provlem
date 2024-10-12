#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin>>t;
    while(t--){
        long long x, y; cin>>x>>y;
        long long cur = max(x, y), prev = cur-1;

        long long start = prev*prev+1, end = cur*cur;
        if(cur%2==0){
            if(x<y) cout<<start+min(x, y)-1<<endl;
            else cout<<end-min(x, y)+1<<endl;
        }else{
            if(x>y) cout<<start+min(x, y)-1<<endl;
            else cout<<end-min(x, y)+1<<endl;
        }
    }
}