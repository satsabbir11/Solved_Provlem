#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        string s;
        cin >> s;

        deque<char> d(s.begin(), s.end());

        int o = 0, in = 0;
        vector<int> v;

        while (!d.empty())
        {
            if (d.front() != d.back())
            {
                in++;
                d.pop_back();
                d.pop_front();
                continue;
            }
            if (o == 300)
                break;
            o++;
            if (d.front() == '1')
            {
                v.push_back(in);
                d.push_front('1');
                d.push_front('0');
            }
            else
            {
                v.push_back(in + d.size());
                d.push_back('0');
                d.push_back('1');
            }
        }

        if (d.size())
            cout << -1 << endl;
        else
        {
            cout << v.size() << endl;
            for (int x : v)
                cout << x << " ";
            cout << endl;
        }
    }
}