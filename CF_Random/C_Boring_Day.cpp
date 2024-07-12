#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n, ll, rr; cin>>n>>ll>>rr;

        queue<int>q;
        int cnt = 0;
        int ans=0, a[n];
        for(int i=0;i<n;i++) cin>>a[i];

        int l=0, r=0;

        while(l<n and r<n){
            cnt+=a[r];
        
            while(cnt>rr and l<=r){
                cnt-=a[l];
                l++;
            }
            if(cnt>=ll and cnt<=rr){
                ans++;
                l=r=r+1;
                cnt=0;
                continue;
            }
            r++;
        }

        cout<<ans<<endl;
    }
}