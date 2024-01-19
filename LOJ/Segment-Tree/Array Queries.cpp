#include<bits/stdc++.h>
using namespace std;


int req(int* tree, int* a, int node, int l, int r){
    if(l==r) return tree[node] = a[l];
    int left = node*2, right= left+1;
    int mid = l + (r-l)/2;

    tree[left] = req(tree, a, left, l, mid);
    tree[right] = req(tree, a, right, mid+1, r);

    return tree[node] = min(tree[left] , tree[right]);
}

int small(int* tree, int* a, int node, int l, int r, int rl, int rr){
    if(rr<l || r<rl) return INT_MAX;
    if(rl<=l && r<=rr) return tree[node];

    int left = node*2, right= left+1;
    int mid = l + (r-l)/2;
    return min(small(tree, a, left, l, mid, rl, rr), small(tree, a, right, mid+1, r, rl, rr));
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    int t;
    cin >> t;
    int j=1;
    while (t--) {
        int n, q;
        cin>>n>>q;
        
        int a[n+2], tree[4*n+10];
        for(int i=1;i<=n;i++) cin>>a[i];
        req(tree, a, 1, 1, n);

        cout<<"Case "<<j++<<": "<<endl;
        while(q--){
            long long l,r;
            cin>>l>>r;
            cout<<small(tree, a, 1, 1, n, l, r)<<endl;
        }
    }
}