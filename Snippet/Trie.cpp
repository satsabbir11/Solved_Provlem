struct Trie
{
    bool lastLetter;
    Trie *children[10];

    Trie()
    {
        for (int i = 0; i < 10; i++)
        {
            lastLetter = false;
            children[i] = nullptr;
        }
    }
};

void insert(string &s, Trie *root)
{
    int n = s.size();

    for (char c : s)
    {
        int index = c - '0';
        if (root->children[index] == nullptr)
            root->children[index] = new Trie();
        root = root->children[index];
    }
    root->lastLetter = true;
}

bool isPrefix(Trie *node)
{
    for (int i = 0; i < 10; i++)
    {
        if (node->children[i] != nullptr)
        {
            if (node->lastLetter)
                return true;
            if (isPrefix(node->children[i]))
                return true;
        }
    }
    return false;
}

void clear(Trie *node)
{
    for (int i = 0; i < 10; i++)
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
    long long t, k = 0;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        Trie *root = new Trie();

        while (n--)
        {
            string s;
            cin >> s;
            insert(s, root);
        }

        bool f = !isPrefix(root);
        cout << loj(++k, con) << endl;
        clear(root);
    }
}