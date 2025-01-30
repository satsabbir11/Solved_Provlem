#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    int freq = 0;
    array<unique_ptr<Trie>, 4> children = {nullptr, nullptr, nullptr, nullptr};

    Trie() = default;
};

int getIndex(char c) {
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        default: throw invalid_argument("Invalid character in string");
    }
}

void insert(const string& s, Trie* root) {
    for (char c : s) {
        int i = getIndex(c);
        if (!root->children[i]) {
            root->children[i] = make_unique<Trie>();
        }
        root = root->children[i].get();
        root->freq++;
    }
}

void search(int depth, Trie* root, int& maxVal) {
    maxVal = max(maxVal, depth * root->freq);
    for (const auto& child : root->children) {
        if (child) {
            search(depth + 1, child.get(), maxVal);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int caseNum = 1; caseNum <= t; ++caseNum) {
        int n;
        cin >> n;

        auto root = make_unique<Trie>();

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            insert(s, root.get());
        }

        int maxVal = 0;
        search(0, root.get(), maxVal);

        cout << "Case " << caseNum << ": " << maxVal << '\n';
    }

    return 0;
}
