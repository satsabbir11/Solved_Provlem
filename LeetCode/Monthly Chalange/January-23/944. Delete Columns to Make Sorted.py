class Solution:
     def minDeletionSize(self, strs):
        leng = len(strs[0])
        ans = 0
        leng-=1

        while leng >= 0:
            f = True
            for i in range(len(strs)-1):
                if strs[i][leng] > strs[i+1][leng]:
                    f = False
            if not f:
                ans += 1
            leng -= 1
        return ans
      
object = Solution()
print(object.minDeletionSize(["cba","daf","ghi"]))
