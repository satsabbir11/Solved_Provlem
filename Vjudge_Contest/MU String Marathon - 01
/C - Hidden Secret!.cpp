#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "Yes" : "No")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    string garbage;
    getline(cin, garbage);

    for (int k = 1; k <= t; k++)
    {
        string s, t;
        getline(cin, s);
        getline(cin, t);

        transform(s.begin(), s.end(), s.begin(), ::tolower);
        transform(t.begin(), t.end(), t.begin(), ::tolower);

        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        t.erase(remove(t.begin(), t.end(), ' '), t.end());
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        bool f = (s==t);
        cout<<loj(k, con)<<endl;
    }
}