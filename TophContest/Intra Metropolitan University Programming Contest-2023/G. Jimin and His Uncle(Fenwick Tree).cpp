#include <bits/stdc++.h>
using namespace std;

void update(int i, int val, int n, int *tree)
{
    while (i <= n)
    {
        tree[i] += val;
        i += (i & -i);
    }
}

int getSum(int i, int *tree)
{
    int sum = 0;
    while (i > 0)
    {
        sum += tree[i];
        i ^= (i & -i);
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        int tree[n + 2] = {}, v[n + 2];

        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            update(i, v[i], n, tree);
        }

        while (q--)
        {
            int type;
            cin >> type;

            if (type == 1)
            {
                int i, val;
                cin >> i >> val;

                int diff = val - v[i];
                v[i] = val;

                update(i, diff, n, tree);
            }
            else
            {
                int l, r, s;
                cin >> l >> r >> s;

                int sum = getSum(r, tree) - getSum(l - 1, tree);

                if (sum == s)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
}