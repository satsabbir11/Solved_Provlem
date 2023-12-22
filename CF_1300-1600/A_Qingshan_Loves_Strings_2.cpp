#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int cnt0 = 0;
        for (int i = 0; i < n; ++i) cnt0 += s[i] == '0';
        if (cnt0 != n-cnt0)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> v;
        deque<char> q;
        for (int i = 0; i < s.length(); ++i)
            q.push_back(s[i]);

        int cnt = 0;
        while (!q.empty())
        {
            if (q.front() == q.back())
            {
                if (q.front() == '0')
                {
                    q.push_back('0');
                    q.push_back('1');
                    v.push_back(n - cnt);
                }
                else
                {
                    q.push_front('1');
                    q.push_front('0');
                    v.push_back(cnt);
                }
                n += 2;
            }
            while (!q.empty() && q.front() != q.back())
            {
                q.pop_back();
                q.pop_front();
                cnt++;
            }
        }

        cout << v.size() << endl;
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
}