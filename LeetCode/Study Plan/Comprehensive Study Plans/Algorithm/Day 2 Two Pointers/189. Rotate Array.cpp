#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> v1, v2;
        int s=nums.size();

        k%=s;

        for(int i=0;i<s;i++){
            if(i>=(s-k)) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }

         for(int i=0;i<v2.size();i++){
           v1.push_back(v2[i]);
        }

         for(int i=0;i<s;i++){
            nums[i]=v1[i];
        }

    }
};

int main(){
    Solution s;
    vector<int> v={1,2,3,4,5,6,7};
    s.rotate(v,3);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}