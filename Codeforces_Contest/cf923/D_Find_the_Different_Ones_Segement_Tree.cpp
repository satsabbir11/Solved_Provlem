#include<bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

struct Node
{
    long long min_val, max_val;
    long long min_index, max_index;
};

void buildSegmentTree(const vector<long long> &arr, vector<Node> &tree, long long start, long long end, long long index)
{
    if (start == end)
    {
        tree[index].min_val = arr[start];
        tree[index].max_val = arr[start];
        tree[index].min_index = start;
        tree[index].max_index = start;
        return;
    }
    long long mid = start + (end - start) / 2;
    buildSegmentTree(arr, tree, start, mid, 2 * index + 1);
    buildSegmentTree(arr, tree, mid + 1, end, 2 * index + 2);
    if (tree[2 * index + 1].min_val < tree[2 * index + 2].min_val)
    {
        tree[index].min_val = tree[2 * index + 1].min_val;
        tree[index].min_index = tree[2 * index + 1].min_index;
    }
    else
    {
        tree[index].min_val = tree[2 * index + 2].min_val;
        tree[index].min_index = tree[2 * index + 2].min_index;
    }
    if (tree[2 * index + 1].max_val > tree[2 * index + 2].max_val)
    {
        tree[index].max_val = tree[2 * index + 1].max_val;
        tree[index].max_index = tree[2 * index + 1].max_index;
    }
    else
    {
        tree[index].max_val = tree[2 * index + 2].max_val;
        tree[index].max_index = tree[2 * index + 2].max_index;
    }
}

Node query(const vector<Node> &tree, long long start, long long end, long long left, long long right, long long index)
{
    if (left <= start && right >= end)
        return tree[index];
    if (left > end || right < start)
        return {INF, -INF, -1, -1};
    long long mid = start + (end - start) / 2;
    Node leftNode = query(tree, start, mid, left, right, 2 * index + 1);
    Node rightNode = query(tree, mid + 1, end, left, right, 2 * index + 2);
    Node result;
    if (leftNode.min_val < rightNode.min_val)
    {
        result.min_val = leftNode.min_val;
        result.min_index = leftNode.min_index;
    }
    else
    {
        result.min_val = rightNode.min_val;
        result.min_index = rightNode.min_index;
    }
    if (leftNode.max_val > rightNode.max_val)
    {
        result.max_val = leftNode.max_val;
        result.max_index = leftNode.max_index;
    }
    else
    {
        result.max_val = rightNode.max_val;
        result.max_index = rightNode.max_index;
    }
    return result;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, q;
        cin >> n;
        vector<long long> arr(n);
        for (long long i = 0; i < n; ++i)
            cin >> arr[i];

        vector<Node> tree(4 * n);
        buildSegmentTree(arr, tree, 0, n - 1, 0);

        cin >> q;

        for (long long i = 0; i < q; ++i)
        {
            long long l, r;
            cin >> l >> r;
            Node result = query(tree, 0, n - 1, l - 1, r - 1, 0);
            // cout << result.min_val << " " << result.max_val << " " << result.min_index + 1 << " " << result.max_index + 1 << endl;
            if (result.min_index == result.max_index)
            {
                cout << -1 << " " << -1 << endl;
            }
            else
            {
                cout << result.min_index + 1 << " " << result.max_index + 1 << endl;
            }
        }
        cout<<endl;
    }
}
