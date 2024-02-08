#include <bits/stdc++.h>
using namespace std;

void build(int *tree, int *a, int node, int l, int r){
    if(l==r){
        tree[node] = a[l];
        return;
    }

    int left = 2*node, right= left+1;
    int mid = (l+r)/2; // l + (r-l)/2
    
    build(tree, a, left, l, mid);
    build(tree, a, right, mid+1, r);

    tree[node] = tree[left] + tree[right];
}

int query(int *tree, int *a, int node, int l, int r, int begin, int end){
    if(r<begin || end<l) return 0;
    
    if(begin<=l && r<=end){
        return tree[node];
    }

    int left = 2*node, right= left+1;
    int mid = (l+r)/2; // l + (r-l)/2

    int left_value = query(tree, a, left, l, mid, begin, end);
    int right_value = query(tree, a, right, mid+1, r, begin, end);

    return left_value+ right_value;
}

void update(int *tree, int *a, int node, int l, int r, int index, int value){
    if(l==r){
        a[l] = value;
        tree[node] = a[l];
        return;
    }

    int left = 2*node, right= left+1;
    int mid = (l+r)/2;

    if(index<=mid) update(tree, a, left, l, mid, index, value);
    else update(tree, a, right, mid+1, r, index, value);
    
    tree[node] = tree[left] + tree[right];
}


int main(){
    int n;
    cin>>n;

    int a[n+2], tree[4*n];
    for(int i=1;i<=n;i++) cin>>a[i];
    // for(int i=1;i<=n;i++) cout<<a[i]<<" ";

    build(tree, a, 1, 1, n);
    int desire_value = query(tree, a, 1, 1, n, 2, 4);
    update(tree, a, 1, 1, n, 3, 10);
    int after_updated_value = query(tree, a, 1, 1, n, 2, 4);


    cout<<desire_value<<" "<<after_updated_value<<endl;
}