#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
     int searchInsert(vector<int> &nums, int target){
        int l=1, r=nums.size();

        if(nums[0]>=target) return 0;

        while(l<r){
            int mid =  l + (r-l)/2;

            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        return l;
     }
};


int main() {
   Solution s;
   vector<int> v = {1,2,4,6,7};
   int target = 1;

   cout<<s.searchInsert(v,target);
}