#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

int lcs(string pattern)
{
    int n = pattern.size();
    vector<int> v(n);
    int index = 0, mx=0;

    for (int i = 1; i < n;)
    {
        if (pattern[i] == pattern[index])
        {
            v[i] = index + 1;
            mx = max(mx, v[i]);
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
    return v[n-1];
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t, k=1;
    cin >> t;
    while (t--) {
        string s;
        cin>>s;

        int l = s.size();

        string t = s;
        reverse(t.begin(), t.end());

        s = t +'#'+s;

        cout<<loj(k, 2*l-lcs(s))<<endl;
        k++;
    }
}