#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) nums[i]*=nums[i];
        sort(nums.begin(), nums.end());
        return nums;
    }
};

int main(){
    Solution s;
    vector<int> v={-4,-1,0,3,10};
    v=s.sortedSquares(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}