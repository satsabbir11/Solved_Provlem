#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i) "Case #" << i << ":"

struct Trie
{
    bool lastLetter;
    Trie *children[26];
    bool picked;

    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            lastLetter = false;
            picked = false;
            children[i] = nullptr;
        }
    }
};

void insert(string &s, Trie *root)
{
    int n = s.size();

    for (char c : s)
    {
        int index = c - 'a';
        if (root->children[index] == nullptr)
            root->children[index] = new Trie();
        root = root->children[index];
    }
    root->lastLetter = true;
}

void clear(Trie *node)
{
    for (int i = 0; i < 26; i++)
    {
        if (node->children[i] != nullptr)
        {
            clear(node->children[i]);
            node->children[i] = nullptr;
        }
    }
    delete (node);
}

void getString(Trie *node, vector<string> &vv, bool f, string s, string &pat, int &sz, int in)
{
    for (int i = 0; i < 26; i++)
    {
        char c = (char)(i + 'a');
        if (node->children[i] != nullptr)
        {
            if (sz > in) if(f) getString(node->children[i], vv, f, s + c, pat, sz, in);
            else if (pat[in - 1] == c)
            {
                if (sz == in)
                    getString(node->children[i], vv, true, s + c, pat, sz, in + 1);
                else if (sz < in)
                    getString(node->children[i], vv, f, s + c, pat, sz, in + 1);
            }
        }
        else if(f && node->lastLetter)
        {
            vv.push_back(s);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n, k;
    cin >> n;

    Trie *root = new Trie();

    while (n--)
    {
        string s;
        cin >> s;
        insert(s, root);
    }

    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        string pat;
        cin >> pat;
        vector<string> vv;
        string s;
        int l = pat.size();
        getString(root, vv, false, s, pat, l, 1);

        cout << loj(i) << endl;
        for (string s : vv)
            cout << s << endl;
        if (vv.size() == 0)
            cout << "No match." << endl;
    }

    clear(root);
}