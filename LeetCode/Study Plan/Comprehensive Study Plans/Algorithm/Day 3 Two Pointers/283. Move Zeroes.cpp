#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>p;
        int cnt=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]) p.push_back(nums[i]);
            else cnt++;
        }

        for(int i=0;i<cnt;i++) p.push_back(0);

        for(int i=0;i<nums.size();i++){
            nums[i]=p[i];
        }
    }
};

int main(){
    Solution s;
    vector<int> v={0,1,0,3,12};
    s.moveZeroes(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}