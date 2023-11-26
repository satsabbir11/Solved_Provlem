#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Manacher
{
public:
    Manacher(string s)
    {
        build(s);
    }

    string getLongestPalindrome()
    {
        return longestPalindrome();
    }

private:
    vector<int> p;
    string s;

    void run_manacher(string s)
    {
        int n = s.size();
        p.assign(n, 0);
        int c = 0, r = 0;

        for (int i = 0; i < n; i++)
        {
            int mirr = 2 * c - i; // Mirror of i

            if (i < r)
                p[i] = min(r - i, p[mirr]);

            // Attempt to expand palindrome centered at i
            while (i + 1 + p[i] < n && i - 1 - p[i] >= 0 && s[i + 1 + p[i]] == s[i - 1 - p[i]])
                p[i]++;

            // If palindrome centered at i expands past right boundary,
            // adjust center and boundaries
            if (i + p[i] > r)
            {
                c = i;
                r = i + p[i];
            }
        }
    }

    void build(string s)
    {
        this->s = s;
        string t = "#"; // Sentinel character
        for (char c : s)
        {
            t += c;
            t += '#';
        }
        run_manacher(t);
    }

    string longestPalindrome()
    {
        int maxLen = 0;
        int center = 0;
        int n = p.size();

        for (int i = 0; i < n; i++)
        {
            if (p[i] > maxLen)
            {
                maxLen = p[i];
                center = i;
            }
        }

        // Calculate the starting index of the longest palindrome
        int start = (center - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    Manacher S(s);
    cout << S.getLongestPalindrome().size() << endl;
}
