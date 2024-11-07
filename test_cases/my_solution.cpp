#include <bits/stdc++.h>
using namespace std;

int  main(){
    long long t; cin>>t;
    while(t--){
        long long n, m; cin>>n;
        queue<long long >v;

        m=n;

        vector<long long >vv(n);

       for(long long i=0; i<n; i++){
            long long x; cin>>x;
            vv[i]=x;
        }
        long long cnt =0, i=0;
        map<long long , long long >mp;

        v.push(vv[i++]);
        
        while(!v.empty()){
            long long x = v.front();
            v.pop();

            mp[x]++;
            cnt++;
           
            if(mp[x]!=2){
                cout<<cnt<<" ";
                if(i<m) v.push(vv[i++]);
            }else{
                cnt-=2;
                mp[x]=0;
                v.push(2*x);
            }
        }
        cout<<endl;
    }
}