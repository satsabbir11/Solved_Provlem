#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

/*
Condition: How many subtring exist such that only one subsquence occur.

to achieve that we much need to go first to last, otherwise
there is a chance to go to start or end position.

So we must go to first to last.

Answer: possible first to last
*/

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        
        long long a[n+2];
        map<long long , bool>mp, first, last;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
            if(!mp[a[i]]){
                first[i] = true;
                mp[a[i]] = true;
            }
        }
        mp.clear();
        for(long long i=n;i>=1;i--){
            if(!mp[a[i]]){
                last[i] = true;
                mp[a[i]] = true;
            }
        }

        long long cnt = 0, ans = 0;

        for(long long i=1;i<=n;i++){
            if(first[i]) cnt++;
            if(last[i]) ans+=cnt;
        }
        cout<<ans<<endl;
    }
}