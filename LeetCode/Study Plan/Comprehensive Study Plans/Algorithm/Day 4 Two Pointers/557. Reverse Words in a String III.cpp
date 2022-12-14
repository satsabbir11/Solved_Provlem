#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string q, final;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 32)
            {
                reverse(q.begin(), q.end());
                final += q;
                final += " ";
                q.clear();
            }
            else
                q += s[i];
        }
        reverse(q.begin(), q.end());
        final += q;
        return final;
    }
};

int main()
{
    Solution s;
    string v = "Let's take LeetCode contest";
    cout << s.reverseWords(v);
    return 0;
}