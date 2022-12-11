#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBadVersion(int n)
    {
        if (n <= 10 && n >= 2)
            return true;
        return false;
    }

public:
    int firstBadVersion(int n) {
        int l=1, r=n;
        while(l<r){
            int mid = l + (r-l)/2;

            if(isBadVersion(mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};

int main()
{
    Solution s;
    cout<<s.firstBadVersion(5);
    return 0;
}