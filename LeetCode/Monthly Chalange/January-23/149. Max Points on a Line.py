class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        slopes = []
        m=0

        for i in range(len(points) - 1):
            for j in range(i + 1, len(points)):
                if (points[i][0] - points[j][0])==0:
                    m = (points[i][1] - points[j][1]) / 100000
                else:
                    m = (points[i][1] - points[j][1]) / (points[i][0] - points[j][0])
                slopes.append(m)

        # Count the occurrences of each number in the slopes list
        counts = Counter(slopes)

        # Find the most frequent number
        most_frequent_number = max(counts, key=counts.get)
        return counts[most_frequent_number]