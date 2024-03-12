#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k; cin>>n>>k;

    vector<long long>v;
    long long cnt=0;
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            v.emplace_back(i);
            long long j = n/i;
            if(i!=j) v.emplace_back(j);
        }
    }

    sort(v.begin(), v.end());


    if(v.size()>=k) cout<<v[k-1]<<endl;
    else cout<<-1<<endl;
}