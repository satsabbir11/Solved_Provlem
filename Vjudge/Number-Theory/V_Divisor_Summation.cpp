#include <bits/stdc++.h>
using namespace std;

int getD(int n){
    int sum=-n;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            sum+=i;
            if(n/i != i) sum+=(n/i);
        }
    }
    return sum;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        cout<<getD(n)<<endl;
    }
}