#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool compare(int arr1[], int arr2[])
    {
        for (int i = 0; i < 27; i++)
            if (arr1[i] != arr2[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p)
    {
        int lenb = s.length(), lens = p.length();
        vector<int> v;
        if (lenb < lens)
            return v;

        int a[27] = {}, b[27] = {};

        for (int i = 0; i < lens; i++)
            a[p[i] - 'a']++;

        for (int i = 0; i < lens; i++)
            b[s[i] - 'a']++;

        int i = lens - 1;

        while (i < lenb)
        {
            int g = i - lens + 1;
            if (compare(a, b))
                v.push_back(g);
            if ((i + 1) < lenb)
            {
                b[s[i + 1] - 'a']++;
                b[s[g] - 'a']--;
            }
            i++;
        }
        return v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    Solution S;

    string s, p;

    cin >> s >> p;

    vector<int> v = S.findAnagrams(s, p);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}