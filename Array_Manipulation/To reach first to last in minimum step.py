#45. jump game II (leetcode)

from typing import List
class Solution:
    def jump(self, nums: List[int]) -> int:
        cur =0
        ans=0
        i=0
        while cur+1<len(nums):
            ans+=1
            now = cur
            for j in range(i,now+1):
                i+=1
                cur = max(cur,j+nums[j])
        return ans
        