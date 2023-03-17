class Solution {
public:
    int min(int a, int b){
        if(a<b) return a;
        else return b;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
    int mid;
    if(l==r) return nums[l];

    while (l <= r)
    {
        mid = (l + r) / 2;

        if(mid%2 == 0 && (nums[mid]==nums[max(0,mid-1)])) r=mid-1;
        else if(mid%2 == 0 && (nums[mid]==nums[ min(mid+1,nums.size()-1)])) l=mid+1;

        else if(mid%2 == 1 && (nums[mid]==nums[max(0,mid-1)])) l=mid+1;
        else if(mid%2 == 1 && (nums[mid]==nums[min(mid+1,nums.size()-1)])) r=mid-1;

        else l=mid+1;
    }

    return nums[max(0,l-1)];
    }
};