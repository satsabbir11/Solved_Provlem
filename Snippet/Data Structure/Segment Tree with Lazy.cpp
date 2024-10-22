#include <bits/stdc++.h>
using namespace std;

template <class T>
struct SegmentTree
{
    // Vectors to store the segment tree, lazy propagation array, and input array
    vector<T> tree, lazy, a;
    int n;

    // Constructor to initialize the size of the segment tree and lazy array
    SegmentTree(int size)
    {
        n = size;
        tree.resize(4 * n);  // Segment tree needs 4 * n space
        lazy.resize(4 * n);  // Lazy array also needs 4 * n space
        a.resize(n + 1);     // Input array with 1-based indexing
    }

    // Function to build the segment tree
    void build_tree(int node, int l, int r)
    {
        lazy[node] = 0;  // Initialize lazy value as 0
        if (l == r)  // If it's a leaf node (base case)
        {
            tree[node] = a[l];  // Set the value of the leaf node
            return;
        }

        // Calculate left and right child, and mid-point of the range
        int left = 2 * node, right = left + 1, mid = l + (r - l) / 2;

        // Recursively build the left and right children
        build_tree(left, l, mid);
        build_tree(right, mid + 1, r);

        // Set the current node value as the sum of its children
        tree[node] = tree[left] + tree[right];
    }

    // Propagate lazy values to children nodes
    void propagate(int node, int l, int r)
    {
        if (lazy[node])  // If there is a pending update
        {
            tree[node] += (r - l + 1) * lazy[node];  // Apply the pending update to the current node

            if (l != r)  // If it's not a leaf node, propagate to children
            {
                lazy[2 * node] += lazy[node];       // Mark left child as lazy
                lazy[2 * node + 1] += lazy[node];   // Mark right child as lazy
            }

            lazy[node] = 0;  // Reset the lazy value for the current node
        }
    }

    // Query function to get the sum in the range [b, e]
    T query(int node, int l, int r, int b, int e)
    {
        propagate(node, l, r);  // Propagate any pending updates

        if (r < b || e < l)  // If the current segment is out of range
            return 0;

        if (b <= l && r <= e)  // If the current segment is fully within the range
            return tree[node];

        // Query the left and right children and return the sum of both
        int mid = l + (r - l) / 2;
        return query(2 * node, l, mid, b, e) + query(2 * node + 1, mid + 1, r, b, e);
    }

    // Update function to add `val` to all elements in the range [b, e]
    void update(int node, int l, int r, int b, int e, T val)
    {
        propagate(node, l, r);  // Propagate any pending updates

        if (r < b || e < l)  // If the current segment is out of range
            return;

        if (b <= l && r <= e)  // If the current segment is fully within the update range
        {
            tree[node] += (r - l + 1) * val;  // Apply the update to the current node
            if (l != r)  // If it's not a leaf node, propagate the update to children
            {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }

        // Update the left and right children
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, b, e, val);
        update(2 * node + 1, mid + 1, r, b, e, val);

        // After updating children, update the current node
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Public function to update the range [l, r] with value `val`
    void update_range(int l, int r, T val)
    {
        update(1, 1, n, l, r, val);  // Update the range [l, r] in the segment tree
    }

    // Public function to query a single point
    T range_query(int l)
    {
        return query(1, 1, n, l, l);  // Query the point `l`
    }

    // Public function to query a range [l, r]
    T range_query(int l, int r)
    {
        return query(1, 1, n, l, r);  // Query the range [l, r]
    }

    // Function to set the input array and build the segment tree
    void set_array(const vector<T>& input)
    {
        for (int i = 1; i <= n; i++)
        {
            a[i] = input[i - 1];  // Set the input array (1-indexed)
        }
        build_tree(1, 1, n);  // Build the segment tree based on the input array
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    // Create a segment tree of size n
    SegmentTree<long long> st(n);

    // Read input array
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Set input array in the segment tree and build it
    st.set_array(arr);

    // Process each query
    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)  // Update query
        {
            int l, r;
            long long val;
            cin >> l >> r >> val;
            st.update_range(l, r, val);  // Update the range [l, r] by adding `val`
        }
        else  // Query for a single point
        {
            int l;
            cin >> l;
            cout << st.range_query(l) << endl;  // Output the value at index `l`
        }
    }

    return 0;
}

// Example:
// Input:
// 8 3
// 3 2 4 5 1 1 5 3
// 2 4
// 1 2 5 1
// 2 4

// Output:
// 5
// 6
