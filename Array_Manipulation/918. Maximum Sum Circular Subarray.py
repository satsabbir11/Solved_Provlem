from typing import List
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n=len(nums)
        # Corner Case
        if (n == 1):
            return nums[0]

        # Initialize sum variable which
        # store total sum of the array.
        sum = 0
        for i in range(n):
            sum += nums[i]

        # Initialize every variable
        # with first value of array.
        curr_max = nums[0]
        max_so_far = nums[0]
        curr_min = nums[0]
        min_so_far = nums[0]

        # Concept of Kadane's Algorithm
        for i in range(1, n):
            # Kadane's Algorithm to find Maximum subarray sum.
            curr_max = max(curr_max + nums[i], nums[i])
            max_so_far = max(max_so_far, curr_max)

            # Kadane's Algorithm to find Minimum subarray sum.
            curr_min = min(curr_min + nums[i], nums[i])
            min_so_far = min(min_so_far, curr_min)
        if (min_so_far == sum):
            return max_so_far

        # returning the maximum value
        return max(max_so_far, sum - min_so_far)

object = Solution()
print (object.maxSubarraySumCircular([1,-2,3,-2]))
