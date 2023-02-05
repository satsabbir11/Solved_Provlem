#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        sort(s1.begin(), s1.end());

        for (int i = 0; i <= (len2 - len1); i++)
        {
            string tem = s2.substr(i, len1);
            sort(tem.begin(), tem.end());
            if (tem == s1)
                return true;
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;

    Solution obj;
    cout << obj.checkInclusion(s1, s2) << endl;
}