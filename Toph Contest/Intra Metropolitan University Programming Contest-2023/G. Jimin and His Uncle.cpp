
#include <bits/stdc++.h>
using namespace std;


// Function to build the Segment Tree
void buildSegmentTree(vector<int> &arr, vector<long long> &segTree, int node, int left, int right)
{
    if (left == right)
    {
        segTree[node] = arr[left];
        return;
    }

    int mid = left + (right - left) / 2;
    buildSegmentTree(arr, segTree, 2 * node + 1, left, mid);
    buildSegmentTree(arr, segTree, 2 * node + 2, mid + 1, right);

    segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
}

// Function to query the Segment Tree for sum in range [l, r]
long long querySegmentTree(vector<long long> &segTree, int node, int left, int right, int l, int r)
{
    if (left > r || right < l) // No overlap
        return 0;
    if (left >= l && right <= r) // Fully contained
        return segTree[node];

    int mid = left + (right - left) / 2;
    return querySegmentTree(segTree, 2 * node + 1, left, mid, l, r) +
           querySegmentTree(segTree, 2 * node + 2, mid + 1, right, l, r);
}

// Function to update the Segment Tree
void updateSegmentTree(vector<long long> &segTree, int node, int left, int right, int index, int value)
{
    if (left == right)
    {
        segTree[node] = value;
        return;
    }

    int mid = left + (right - left) / 2;
    if (index <= mid)
        updateSegmentTree(segTree, 2 * node + 1, left, mid, index, value);
    else
        updateSegmentTree(segTree, 2 * node + 2, mid + 1, right, index, value);

    segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        vector<long long> segTree(4 * n); // The segment tree will have a size of at most 4 times the input array size.

        buildSegmentTree(arr, segTree, 0, 0, n - 1);

        while (q--)
        {
            int type;
            cin >> type;

            if (type == 2)
            {
                int l, r, s;
                cin >> l >> r >> s;
                --l; // Convert to 0-indexed
                --r; // Convert to 0-indexed
                int ans = querySegmentTree(segTree, 0, 0, n - 1, l, r);
                if (ans == s)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else if (type == 1)
            {
                int i, v;
                cin >> i >> v;
                --i; // Convert to 0-indexed
                updateSegmentTree(segTree, 0, 0, n - 1, i, v);
            }
        }
    }

    return 0;
}
