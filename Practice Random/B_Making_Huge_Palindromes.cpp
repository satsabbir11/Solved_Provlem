#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

vector<int>lcs(string pattern)
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
            if (index) index = v[index - 1];
            else
            {
                v[i] = 0;
                i++;
            }
        }
    }
    return v;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t, k=1;
    cin >> t;
    while (t--) {
        string s;
        cin>>s;

        int l = s.size(), mx =0;

        string t = s;
        reverse(t.begin(), t.end());

        s = t +'#'+s;

        vector<int> v = lcs(s);
        cout<<loj(k++, l+l-v[2*l])<<endl;
    }
}