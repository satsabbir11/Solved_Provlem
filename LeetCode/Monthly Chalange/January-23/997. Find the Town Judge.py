class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        cnt = [0 for _ in range(n+1)]
        for i, j in trust:
            cnt[i] -= 1
            cnt[j] += 1
        
        for i in range(1, n+1):
            if cnt[i] == n-1:
                return i
        return -1