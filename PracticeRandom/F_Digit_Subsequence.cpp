#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i <= 1000000; i++)
    {
        string sr = to_string(i);

        if (s.find(sr) >= s.size())
        {
            cout << sr << endl;
            return 0;
        }
    }
}
