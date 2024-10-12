#include <bits/stdc++.h>
using namespace std;

 int main(){
    int n, m; cin>>n>>m;
    vector<int>v, p;
    for(int i=0; i<n;i++){
        int x; cin>>x;
        v.push_back(x);
    }
    for(int i=0; i<m;i++){
        int x; cin>>x;
        p.push_back(x);
    }

    sort(v.begin(), v.end());
    for(auto i:p){
        cout<<upper_bound(v.begin(), v.end(), i)-v.begin()<<" ";
        //cout<<i<<" ";
    }
 }