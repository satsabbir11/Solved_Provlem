#include <bits/stdc++.h>
using namespace std;
int n;

void buildTree(vector<int> &a, vector<int> &tree, int node = 0, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        tree[node] = a[l];
        return;
    }

    int left = 2 * node +1, right = 2 * node + 2;
    int mid = l + (r - l) / 2;

    buildTree(a, tree, left, l, mid);
    buildTree(a, tree, right, mid + 1, r);

    tree[node] = tree[right] + tree[left];
}

void updateTree(int i, int value, vector<int> &tree, int node = 0, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        tree[node] = value;
        return;
    }

    int left = 2 * node +1, right = 2 * node + 2;
    int mid = l + (r - l) / 2;

    if(i<=mid) updateTree(i, value, tree, left, l, mid);
    else updateTree(i, value, tree, right, mid + 1, r);

    tree[node] = tree[right] + tree[left];
}

int getSum(int i, int j, vector<int> &tree, int node = 0, int l = 0, int r = n - 1)
{
    if(i>r || j<l) return 0;
    if(i<=l && r<=j) return tree[node];

    int left = 2 * node +1, right = 2 * node + 2;
    int mid = l + (r - l) / 2;

    return getSum(i, j, tree, left, l, mid) + getSum(i, j, tree, right, mid+1, r);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int q;
        cin >> n >> q;

        vector<int> a(n), tree(4 * n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        buildTree(a, tree);

        while (q--)
        {
            int type;
            cin >> type;

            if (type == 1)
            {
                int index, value;
                cin >> index >> value;
                updateTree(index--, value, tree);
            }

            else
            {
                int l, r, s;
                cin >> l >> r >> s;
                if (getSum(l-1, r-1, tree) == s)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
}