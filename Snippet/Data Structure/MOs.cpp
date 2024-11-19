#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, idx;
};

bool compare(const Query &q1, const Query &q2) {
    int block_size = sqrt(q1.l);
    if (q1.l / block_size != q2.l / block_size)
        return q1.l < q2.l;
    return q1.r < q2.r;
}

class MosAlgorithm {
public:
    vector<int> arr, answers, freq;
    vector<Query> queries;
    int current_answer = 0;

    MosAlgorithm(int n, int q) {
        arr.resize(n);
        answers.resize(q);
        freq.resize(n + 1, 0);
    }

    void add(int idx) {
        freq[arr[idx]]++;
        if (freq[arr[idx]] == 1)
            current_answer++;
    }

    void remove(int idx) {
        if (freq[arr[idx]] == 1)
            current_answer--;
        freq[arr[idx]]--;
    }

    vector<int> processQueries(int n) {
        int block_size = sqrt(n);
        sort(queries.begin(), queries.end(), compare);
        int curr_l = 0, curr_r = -1;
        for (const Query &q : queries) {
            int l = q.l, r = q.r;
            while (curr_r < r) add(++curr_r);
            while (curr_r > r) remove(curr_r--);
            while (curr_l < l) remove(curr_l++);
            while (curr_l > l) add(--curr_l);
            answers[q.idx] = current_answer;
        }
        return answers;
    }

    void addQuery(int l, int r, int idx) {
        queries.push_back({l, r, idx});
    }

    void setArray(const vector<int> &input) {
        arr = input;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    MosAlgorithm mos(n, q);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    mos.setArray(arr);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        mos.addQuery(l, r, i);
    }
    vector<int> results = mos.processQueries(n);
    for (int i = 0; i < q; i++) {
        cout << results[i] << endl;
    }
    return 0;
}
