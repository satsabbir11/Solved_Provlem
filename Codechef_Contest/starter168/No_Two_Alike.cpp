#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j
#define all(s) s.begin(), s.end()

#define bug(a) cout << #a << " : " << a <<endl;

#define int long long

struct MinMax{
    int mn=-1, mx=-1;
};


bool compare(pair<int, MinMax> a, pair<int, MinMax> b){
    return a.second.mx-a.second.mn < b.second.mx-b.second.mn;

}

int32_t main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;

       // convert it to map MinMax g[n+2];

        map<int, MinMax> g;
        
        vector<int> a(n);
        int in =0;

        for(int &x: a){
            cin>>x;
            if(g[x].mn==-1) g[x].mn = in;
            g[x].mx = in;
            in++;
        }

        //sort map by  mx-mn

        vector<pair<int, MinMax>> v(all(g));

        sort(all(v), compare);

        int ans = 0;

        for(int i=0; i<v.size(); i++){
            if(i==0) ans+=v[i].second.mx-v[i].second.mn+1;
            else{
                ans+=v[i].second.mx-v[i].second.mn+1;
                ans-=v[i].second.mx-v[i].second.mn;
            }
        }

    }
}