#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n, k; cin>>n>>k;

    vector<int>div;

    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            div.push_back(i);
            if(i!=n/i)div.push_back(n/i);
        }
    }

    sort(div.begin(), div.end());
    cout<<(div.size()<k?-1:div[k-1])<<endl;
}