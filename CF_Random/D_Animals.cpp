#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);

   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    //cin >> t;
    t=1;
    while (t--) {
        long long n, x, sum =0;
        cin>>n>>x;
        
        long long a[n+2];
        vector<int>v;

        for(long long i=1;i<=n;i++){
            int x;
            cin>>x;
            v.push_back(x*(n-i+1));
        }
        sort(v.begin(), v.end());
        int cnt=0;
        for(int i=0;i<v.size(); i++){
            sum+=v[i];
            if(sum<=x) cnt++;
            else break;
        }
        cout<<cnt<<endl;
    }
}