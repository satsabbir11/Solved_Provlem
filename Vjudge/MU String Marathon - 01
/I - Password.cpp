#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

vector<int> lps(string pattern)
{
    int n = pattern.size();
    vector<int> v(n);
    int index = 0;

    for (int i = 1; i < n;)
    {
        if (pattern[i] == pattern[index])
        {
            v[i] = index + 1;
            i++;
            index++;
        }
        else
        {
            if (index)
                index = v[index - 1];
            else
            {
                v[i] = 0;
                i++;
            }
        }
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    if (n == 1)
    {
        cout << "Just a legend" << endl;
        return 0;
    }

    vector<int> v = lps(s);

    bool f = v[v[n - 1] - 1];

    for (int i = 0; i < n - 1; i++)
    {
        if (v[n - 1] == v[i])
        {
            string t = s.substr(0, v[n - 1]);
            if (t.size() == 0)
            {
                cout << "Just a legend" << endl;
            }
            else
                cout << t << endl;
            return 0;
        }
    }

    // for(int x: v){
    //     cout<<x<<" ";
    // }
    // cout<<endl;

    if (f)
    {
        cout << s.substr(0, v[v[n - 1] - 1]) << endl;
        return 0;
    }

    cout << "Just a legend" << endl;
}
