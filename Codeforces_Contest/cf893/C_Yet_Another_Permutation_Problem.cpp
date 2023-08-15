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
        map<int, bool>mp;
        for(long long i=1;i<=n;i++) mp[i]=false;

        int cnt =1, b[n+2];

        int k=1;

        for(long long i=1;i<=n;i++){
            int f= i;
            while(f<=n && mp[f]==false){
                //cout<<f<<" ";
                b[k++] = f;
                mp[f]=true;
                f*=2;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
        
    }
}