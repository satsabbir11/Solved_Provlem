#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        
        long long a[n+2], dnt=0;
        map<int, int>mp;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
            mp[a[i]]++;
             if(mp[a[i]]==1) dnt++;
        }

        int cnt = n/2;

        bool f= true;

        for(long long i=1;i<=n;i++){
            if(mp[a[i]]<cnt) f=false;
           
        }

        if(dnt>2) f=false;
        cout<<con<<endl;
    }
}