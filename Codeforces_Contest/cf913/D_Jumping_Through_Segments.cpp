#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

bool check(vector<int>&ll, vector<int>&rr, int n, int k){
    int l, r;
    l=r=0;
    for(int i=0;i<n;i++){
        l = max(l-k, ll[i]);
        r = min(r+k, rr[i]);
        if(l>r) return false;
    }
    return true;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        vector<int>ll(n), rr(n);

        for(int i =0;i<n;i++) cin>>ll[i]>>rr[i];

        int l = 0, r = 1e9;

        while(l<r ){
            int mid = l + (r-l)/2;
            if(check(ll, rr, n, mid)) r = mid;
            else l = mid+1;
        }

        cout<<r<<endl;
    }
}