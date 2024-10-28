#include <bits/stdc++.h>
using namespace std;

struct SqrtDecomposition
{
    int n, block_size;
    vector<int> arr, blocks;

    SqrtDecomposition(const vector<int> &input)
    {
        n = input.size();
        block_size = sqrt(n); // Calculate the size of each block
        arr = input;
        blocks.resize((n + block_size - 1) / block_size, 0); // Adjust for the number of blocks

        // Build the initial blocks by summing over ranges
        for (int i = 0; i < n; i++)
        {
            blocks[i / block_size] += arr[i];
        }
    }

    // Query the sum in range [l, r]
    int query(int l, int r)
    {
        l--, r--; // Adjust for 0 indexing
        int sum = 0;

        int start_block = l / block_size;
        int end_block = r / block_size;

        if (start_block == end_block)
        {
            // When l and r are in the same block, sum directly
            for (int i = l; i <= r; i++) sum += arr[i];
        }
        else
        {
            // Sum the partial block from l to the end of its block
            for (int i = l; i < (start_block + 1) * block_size; i++) sum += arr[i];

            // Sum the full blocks in between
            for (int i = start_block + 1; i < end_block; i++) sum += blocks[i];

            // Sum the partial block from the start of r's block to r
            for (int i = end_block * block_size; i <= r; i++) sum += arr[i];
        }

        return sum;
    }

    // Update the value at index idx to val
    void update(int idx, int val)
    {
        idx--; //Adjust for 0 indexing
        int block_idx = idx / block_size;

        // Adjust the block's sum by the difference in values
        blocks[block_idx] += (val - arr[idx]);

        // Update the original array
        arr[idx] = val;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Initialize sqrt decomposition
    SqrtDecomposition sqrtDecomp(a);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l, r;
            cin >> l >> r;

            cout << sqrtDecomp.query(l, r) << endl; // 1 indexing
        }
        else
        {
            int x, val;
            cin >> x >> val;

            sqrtDecomp.update(x, val);  //indexing
        }
    }
    return 0;
}
