#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n, d;
    cin>>n>>d;

    pair<int, int>a[n+4];
    for(int i=1; i<=n; i++) cin>>a[i].first>>a[i].second;

    sort(a+1, a+1+n);

    int i=1, j=1, cnt=0, ans=0;
    while(i<=n){
        cnt+=a[i].second;
        while(j<=i and (a[i].first-a[j].first)>=d){
            cnt-=a[j++].second;
        }
        ans = max(cnt, ans);
        i++;
    }

    cout<<ans<<endl;
}