#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hash[10005];
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 > len2)
            return false;
        else if (len1 == len2)
        {
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            return s1 == s2;
        }

        int sum = 0;
        sort(s1.begin(), s1.end());
        for (int i = 0; i < len1; i++)
            sum += (s1[i] - 'a');

        hash[0] = s2[0] - 'a';
        for (int i = 1; i < len2; i++)
            hash[i] = hash[i - 1] + s2[i] - 'a';

        for (int i = 0; i <= (len2 - len1); i++)
        {
            if ((hash[i + len1 - 1] - hash[max(0, i - 1)]) == sum)
            {
                string tem = s2.substr(i, len1);
                sort(tem.begin(), tem.end());
                if (tem == s1)
                    return true;
            }
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