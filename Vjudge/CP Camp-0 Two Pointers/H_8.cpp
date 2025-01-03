#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

int32_t main(){
    int n; cin>>n;
    int a[n+2];
    vector<int>v[n+2];
    for(int i=1; i<=n; i++){
        cin>>a[i];
        v[a[i]].push_back(i-1);
    }

    // vector<int>g={0, 1, 5};

    int q; cin>>q;
    while (q--)
    {
        int l, r, x;
        cin>>l>>r>>x;

        int yy=lower_bound(all(v[x]), r)-v[x].begin();
        int xx=lower_bound(all(v[x]), l-1)-v[x].begin(); 
        
        int ans=yy-xx;
        //if(v[x][xx]==l) ans=yy-xx+1;
        //else ans=yy-xx;
        cout<<ans<<endl;
    }
    //cout<<lower_bound(all(g), 3)-g.begin()<<endl;
}

//it something hard to explain
//let's clear it together


//lower bound of x means what is the position of x?
//if x isn't exist where should it's index?

//initially we put i-1, but our l, r is same our target is l to r so,
//we take all the value between l-1 to r (main index is l to r-1)