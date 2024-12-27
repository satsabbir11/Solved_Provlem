#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    string s;
    cin>>n>>s;

    int cnt = 0, tot, ans=n;
    map<int, int>mp;

    set<char>ss;
    for(char x: s) ss.insert(x);

    tot=ss.size();

    int i=0, j=0;
    while(i<n){
        mp[s[i]]++;
        if(mp[s[i]]==1) cnt++;
        while(j<=i and mp[s[j]]>1){
            mp[s[j++]]--;
        }
        if(cnt==tot) ans=min(ans, i-j+1);
        i++;
    }
    cout<<ans<<endl;
}