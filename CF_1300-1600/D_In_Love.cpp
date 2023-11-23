#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (ff ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    multiset<int> f, s;
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;

        if (c == '+')
        {
            f.insert(l);
            s.insert(r);
        }
        else
        {
            f.erase(f.find(l));
            s.erase(s.find(r));
        }

        bool ff = true;
        if (s.empty() || *f.rbegin() <= *s.begin()) //if that happened that means, always start before end, and that means something common
            ff = false;

        cout << con << endl;
    }
}