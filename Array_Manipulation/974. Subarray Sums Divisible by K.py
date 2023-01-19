from typing import List
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        mp = [0]*(k+1)
        cum = 0
        cnt = 0
        
        for num in nums:
            cum = (((cum + num) % k)+k)%k
            mp[cum] += 1
        
        for i in range(k+1):
            cnt += mp[i]*(mp[i]-1)//2
        
        cnt += mp[0]
        
        return cnt

object = Solution()
print (object.subarraysDivByK([4,5,0,-2,-3,1], 5))