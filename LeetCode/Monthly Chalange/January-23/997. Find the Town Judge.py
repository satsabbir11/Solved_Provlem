class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        cnt = 0 
        mp,m = [],[]
        for i in range(len(trust)):
            mp.append(trust[i][1])
            m.append(trust[i][0])
            
            
        for i in range (1,n+1):
            if (mp.count(i)==n-1 and m.count(i)==0):
                return i
        return -1