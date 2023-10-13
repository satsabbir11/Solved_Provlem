#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int mx = 0;

struct Trie
{
    int freq;
    Trie *children[4];

    Trie()
    {
        freq = 0;
        for (int i = 0; i < 4; i++)
        {
            children[i] = nullptr;
        }
    }
};

void insert(string &s, Trie *root)
{
    int n = s.size();

    for (char c : s)
    {
        int index;
        if (c == 'A')
            index = 0;
        else if (c == 'T')
            index = 1;
        else if (c == 'C')
            index = 2;
        else
            index = 3;

        if (root->children[index] == nullptr)
            root->children[index] = new Trie();

        root = root->children[index];
        root->freq++;
    }
}

void search(Trie *node, int cnt)
{
    mx = max(cnt * node->freq, mx);
    for (int i = 0; i < 4; i++)
    {
        if (node->children[i] != nullptr)
            search(node->children[i], cnt + 1);
    }
}

void clear(Trie *node)
{
    for (int i = 0; i < 4; i++)
    {
        if (node->children[i] != nullptr)
        {
            clear(node->children[i]);
            node->children[i] = nullptr;
        }
    }
    delete (node);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t, k = 0;
    cin >> t;
    while (t--)
    {
        mx = 0;
        long long n;
        cin >> n;

        Trie *root = new Trie();

        while (n--)
        {
            string s;
            cin >> s;
            insert(s, root);
        }

        search(root, 0);

        cout << loj(++k, mx) << endl;
        clear(root);
    }
}