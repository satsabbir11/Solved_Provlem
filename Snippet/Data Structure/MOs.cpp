#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, idx;
};

// Comparator to sort queries in the required order
bool compare(const Query &q1, const Query &q2) {
    int block_size = sqrt(q1.l); // Change block size based on `n`
    if (q1.l / block_size != q2.l / block_size)
        return q1.l < q2.l;  // Sort by block
    return q1.r < q2.r;      // Sort by r if in the same block
}

class MosAlgorithm {
public:
    vector<int> arr;
    vector<int> answers;
    vector<Query> queries;
    vector<int> freq;  // To maintain frequency of elements
    int current_answer = 0; // Stores the current result for a range (e.g., sum or distinct count)

    // Initialize array size and query count
    MosAlgorithm(int n, int q) {
        arr.resize(n);
        answers.resize(q);
        freq.resize(n + 1, 0);  // Adjust size according to the max element in arr
    }

    // Adjust current_answer by adding an element
    void add(int idx) {
        // Add arr[idx] to the current range
        // Example for distinct count:
        freq[arr[idx]]++;
        if (freq[arr[idx]] == 1) 
            current_answer++;
    }

    // Adjust current_answer by removing an element
    void remove(int idx) {
        // Remove arr[idx] from the current range
        // Example for distinct count:
        if (freq[arr[idx]] == 1)
            current_answer--;
        freq[arr[idx]]--;
    }

    // Process queries using Mo's algorithm
    vector<int> processQueries(int n) {
        int block_size = sqrt(n);

        // Sort queries according to Mo's order
        sort(queries.begin(), queries.end(), compare);

        // Initialize the current range [l, r]
        int curr_l = 0, curr_r = -1;

        for (const Query &q : queries) {
            int l = q.l, r = q.r;

            // Expand the current range to the right
            while (curr_r < r) add(++curr_r);
            // Contract the current range from the right
            while (curr_r > r) remove(curr_r--);

            // Expand the current range to the left
            while (curr_l < l) remove(curr_l++);
            // Contract the current range from the left
            while (curr_l > l) add(--curr_l);

            // Store the result for this query
            answers[q.idx] = current_answer;
        }

        return answers;
    }

    // Add a query to the list
    void addQuery(int l, int r, int idx) {
        queries.push_back({l, r, idx});
    }

    // Set the array of values
    void setArray(const vector<int> &input) {
        arr = input;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    MosAlgorithm mos(n, q);

    // Input array
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mos.setArray(arr);

    // Input queries
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;  // 0-based indexing
        mos.addQuery(l, r, i);
    }

    // Process all queries
    vector<int> results = mos.processQueries(n);

    // Output the results for each query
    for (int i = 0; i < q; i++) {
        cout << results[i] << endl;
    }

    return 0;
}
