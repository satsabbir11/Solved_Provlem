#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        map<int, int>mp;

        vector<int>p;

        for (int i = 0; i < numbers.size(); i++)
            mp[numbers[i]] = 1;

        int f=-1, g;

        for (int i = 0; i < numbers.size(); i++)
        {
            f = target - numbers[i];
            if (mp[f])
            {
                p.push_back(i+1);
                g=i;
                break;
            }
        }

        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == f && i!=g){
                p.push_back(i+1);
                break;
            }
        }

        sort(p.begin(), p.end());

        return p;
    }
};

int main()
{
    Solution s;
    vector<int> v = {2, 7, 11, 15};
    v = s.twoSum(v, 9);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}