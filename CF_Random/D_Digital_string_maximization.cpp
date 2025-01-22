#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int i = 1;

        while (i < n)
        {

            while (i > 0)
            {
                if (s[i] != '0' and s[i] > (s[i - 1] + 1))
                {
                    s[i]--;
                    swap(s[i], s[i - 1]);
                }
                else
                    break;
                i--;
            }
            i++;
        }

        cout << s << endl;
    }
}

/*
Observation: You can move maximum 8 time back by a number ex: 9->  8->7->6->5->4->3->2->1 
So,
Step 1: Start from first then move to back , when not possible break (max 8 times)
Step 2: Move forward digit, do same thing(Step 1) for this digit (n times)
Time Complexity: O(8*n) ~ O (n)
*/