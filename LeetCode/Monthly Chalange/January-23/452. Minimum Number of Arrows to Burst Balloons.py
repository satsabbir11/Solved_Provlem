class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])

        p = points[0][1]
        cnt = 0

        for i in range(1, len(points)):
            if points[i][0] > p:
                p = points[i][1]
                cnt += 1

        return cnt + 1