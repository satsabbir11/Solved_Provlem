#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long a[n+2];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a, a+n);
        cout<<max(a[n-1]*a[n-2], a[0]*a[1])<<endl;
    }
}