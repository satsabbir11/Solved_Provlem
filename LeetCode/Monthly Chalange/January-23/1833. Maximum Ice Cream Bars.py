class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        cnt=0
        total=0
        for cost in costs:
            total+=cost
            if total<=coins:
                cnt+=1
        return cnt